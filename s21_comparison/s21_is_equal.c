#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
    s21_comparison_result result_num = S21_COMPARISON_TRUE;
    int ret = (s21_zero((unsigned *)value_1.bits, 3) &&
             s21_zero((unsigned *)value_2.bits, 3));
    if (!ret) {
    s21_big_decimal arr1, arr2;
    s21_decimal_to_s21_big_decimal(value_1, &arr1);
    s21_decimal_to_s21_big_decimal(value_2, &arr2);
    ret = (s21_get_sign(value_1) == s21_get_sign(value_2)) &&
          (s21_bit_compare(arr1.bits, arr2.bits, 12) == 0);
  }
  return ret;
}