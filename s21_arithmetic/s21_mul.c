#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_arithmetic_result result_num = S21_ARITHMETIC_OK;

    /* .... */

    return result_num;
}

void s21_mul_big(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result) {
  s21_zero_array(result->bits, 12);
  for (int i = 0; i < 6; ++i) {
    for (int k = 0; k < 6; ++k) {
      unsigned long long int m =
          (unsigned long long)value_1.bits[k] * value_2.bits[i] +
          result->bits[i + k];
      result->bits[i + k] = m & 0xFFFFFFFF;
      unsigned overflow = m >> 32;
      for (int p = i + k + 1; p < 12; p++) {
        unsigned long long int tmp = overflow;
        tmp += result->bits[p];
        result->bits[p] = tmp & 0xFFFFFFFF;
        overflow = tmp >> 32;
      }
    }
  }
  for (int d = 0; d < 28; ++d) {
    s21_div10(result->bits, 12);
  }
}