#include "../s21_decimal.h"

int s21_get_scale(s21_decimal num) {
    int mask = 0b11111111; // 8 битов или 255 в десятичной
    mask <<= 16;
    mask = num.bits[3] & mask;
    mask >>= 16;
    return mask;
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

void s21_decimal_to_s21_big_decimal(s21_decimal value, s21_big_decimal* big_value) {
    int degree = 28 - s21_get_scale(value);
    s21_zero_s21_decimal(big_value->bits, 12);
    s21_copy_decimal((unsigned *)value.bits, big_value->bits, 3);
    for (int i = 0; i < degree; ++i) s21_big_decimal_mul_10(big_value->bits, 12);
}

