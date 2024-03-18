#include "../s21_decimal.h"

void s21_set_bit(s21_decimal *num, int index, int value) {
  if (value == 1) {
    num->bits[index / 32] =
        num->bits[index / 32] |
        (1 << index % 32);  // (1 << bit % 32) создает число, у которого только
                            // один бит равен 1 на позиции bit % 32
  } else if (value == 0) {
    num->bits[index / 32] =
        num->bits[index / 32] & ~(1 << index % 32);  // инвертированная маска
  }
}

int s21_bit_compare(const unsigned *arr_1, const unsigned *arr_2, int count) {
  int ret = 0;
  for (int i = count - 1; i >= 0 && !ret; i--) {
    if (arr_1[i] != arr_2[i]) {
      ret = arr_1[i] > arr_2[i] ? 1 : -1;
    }
  }
  return ret;
}

int s21_get_scale(s21_decimal num) {
  int mask = 0b11111111;  // 8 битов или 255 в десятичной
  mask <<= 16;
  mask = num.bits[3] & mask;
  mask >>= 16;
  return mask;
}

int s21_set_scale(s21_decimal *num, int scale) {
  int result = 0;
  if (scale < 256 && scale >= 0) {  // масштаб от 0 до 255 correctly
    for (int i = 0; i < 8; i++) {   // 8 бит для масштаба
      s21_set_bit(num, i + MAX_BLOCK_BITS / 2 + MAX_BLOCK_NUMBER, scale % 2);
      scale >>= 1;
    }
  } else
    result = 1;
  return result;
}

int s21_decimal_is_zero(const unsigned *arr, int count) {
  int ret = 1;
  for (int i = 0; i < count && ret; i++) {
    ret = arr[i] == 0;
  }
  return ret;
}

void s21_zero_s21_decimal(unsigned *array, int count) {
  for (int i = 0; i < count; ++i) array[i] = 0;
}

void s21_copy_decimal(const unsigned *array1, unsigned *array2, int count) {
  for (int i = 0; i < count; ++i) array2[i] = array1[i];
}

void s21_big_decimal_mul_10(unsigned *arr, int count) {
  unsigned long long int overflow = 0;
  for (int k = 0; k < count; ++k) {
    unsigned long long int tmp = arr[k];
    tmp *= 10;
    tmp += overflow;
    arr[k] = tmp & 0xFFFFFFFF;
    overflow = tmp >> 32;
  }
}

void s21_big_decimal_div10(unsigned *arr, int count) {
  unsigned long long int mod = 0;
  for (int i = count - 1; i >= 0; i--) {
    unsigned long long int tmp = mod << 32;
    tmp += arr[i];
    arr[i] = tmp / 10;
    mod = tmp % 10;
  }
}

int s21_big_decimal_mod10(const unsigned *arr, int count) {
  unsigned arrTmp[12];
  s21_copy_decimal(arr, arrTmp, 12);
  unsigned long long int mod = 0;
  for (int i = count - 1; i >= 0; i--) {
    unsigned long long int tmp = mod << 32;
    tmp += arrTmp[i];
    arrTmp[i] = tmp;
    mod = tmp % 10;
  }
  return mod;
}

void s21_big_decimal_add(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result) {
  if (result) {
    s21_zero_s21_decimal(result->bits, 12);
    unsigned overflow = 0;

    for (int i = 0; i < 12; ++i) {
      unsigned long long int tmp = overflow;
      tmp += (unsigned)value_1.bits[i];
      tmp += (unsigned)value_2.bits[i];
      result->bits[i] = tmp & 0xFFFFFFFF;
      overflow = tmp >> 32;
    }
  }
}

void s21_decimal_to_s21_big_decimal(s21_decimal value,
                                    s21_big_decimal *big_value) {
  int degree = 28 - s21_get_scale(value);
  s21_zero_s21_decimal(big_value->bits, 12);
  s21_copy_decimal((unsigned *)value.bits, big_value->bits, 3);
  for (int i = 0; i < degree; ++i) s21_big_decimal_mul_10(big_value->bits, 12);
}

int s21_big_decimal_to_s21_decimal(s21_big_decimal big_value,
                                   s21_decimal *value) {
  int newScale = 28;  // Изначально новый масштаб равен максимальному
  int mod = 0;  // Инициализация остатка от деления на 10
  int ret = 0;  // Переменная для хранения результата округления

  // Обработка незначащих нулей
  while (!s21_big_decimal_mod10(big_value.bits, 12) && newScale > 0) {
    s21_big_decimal_div10(big_value.bits, 12);
    newScale--;
  }

  // Отбрасывание дробной части до тех пор, пока мантисса не помещается в int[3]
  while (!s21_decimal_is_zero(big_value.bits + 3, 9) && newScale > 0) {
    mod = s21_big_decimal_mod10(big_value.bits, 12);
    s21_big_decimal_div10(big_value.bits, 12);
    newScale--;
  }

  // Банковское округление
  ret = s21_round_bank(&big_value, mod, &newScale);

  // Копирование результата в value, если результат успешный
  if (value) {
    if (!ret) {
      s21_copy_decimal(big_value.bits, (unsigned *)value->bits, 3);
      s21_set_scale(value, newScale);
    } else {
      s21_zero_s21_decimal((unsigned *)value, 4);
    }
  }
  return ret;
}

int s21_round_bank(s21_big_decimal *big_value, int mod, int *newScale) {
  int ret = !s21_decimal_is_zero(big_value->bits + 3, 9);
  if (!ret && (mod > 5 || (mod == 5 && (big_value->bits[0] & 1)))) {
    // проверяем краевые значения (на переполнения)
    unsigned max_mantisa[] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
    if (!s21_bit_compare(big_value->bits, max_mantisa, 3)) {
      if (*newScale > 0) {
        mod = s21_big_decimal_mod10(big_value->bits, 12);
        s21_big_decimal_div10(big_value->bits, 12);
        (*newScale)--;
      } else {
        ret = 1;
      }
    }
    s21_big_decimal one;
    s21_zero_s21_decimal(one.bits, 12);
    one.bits[0] = 1;
    s21_big_decimal_add(*big_value, one, big_value);
  }
  return ret;
}

int main() {
  s21_decimal value = {-123, -456, -789};  // пример значения s21_decimal
  s21_big_decimal big_value;  // для хранения результата 1
  s21_decimal s21_value;      // для хранения результата 2

  printf("Starting value: ");
  for (int i = 0; i < 4; ++i) {
    printf("%u ", value.bits[i]);
  }

  printf("\n");

  s21_decimal_to_s21_big_decimal(value, &big_value);

  printf("Converted value to big decimal: ");
  for (int i = 0; i < 12; ++i) {
    printf("%u ", big_value.bits[i]);
  }
  printf("\n");

  s21_big_decimal_to_s21_decimal(big_value, &s21_value);

  printf("Converted value from big decimal: ");
  for (int i = 0; i < 4; ++i) {
    printf("%u ", s21_value.bits[i]);
  }

  return 0;
}
