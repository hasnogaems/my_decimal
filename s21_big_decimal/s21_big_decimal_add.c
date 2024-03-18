#include "../s21_decimal.h"

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
