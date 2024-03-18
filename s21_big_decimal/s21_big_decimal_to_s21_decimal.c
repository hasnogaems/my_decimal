#include "../s21_decimal.h"

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
