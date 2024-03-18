#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
    s21_comparison_result result_num = S21_COMPARISON_FALSE;
    int ret = 0;
  if (!(s21_zero((unsigned *)value_1.bits, 3) &&
        s21_zero((unsigned *)value_2.bits, 3))) {
    int sign1 = s21_get_sign(value_1) ? -1 : 1;
    int sign2 = s21_get_sign(value_2) ? -1 : 1;
    if (sign1 != sign2) {
      ret = sign1 < sign2;
    } else {
      s21_big_decimal arr1, arr2;
      s21_decimal_to_s21_big_decimal(value_1, &arr1);
      s21_decimal_to_s21_big_decimal(value_2, &arr2);
      ret = s21_bit_compare(arr1.bits, arr2.bits, 12) + sign1 == 0;
    }
  }
  return ret;
}