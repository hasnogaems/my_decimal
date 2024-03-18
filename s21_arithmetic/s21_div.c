#include "../s21_decimal.h"
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = bits_zero_check((unsigned *)value_2.bits, 3) ? 3 : 0;
  if (!ret) {
    s21_decimal max_num = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_big_decimal arr1, arr2, arr_max, arr_res;

    s21_decimal_to_s21_big_decimal(value_1, &arr1);
    s21_decimal_to_s21_big_decimal(value_2, &arr2);
    s21_decimal_to_s21_big_decimal(max_num, &arr_max);
    s21_mul28(arr2, arr_max, &arr_res);
    if (s21_bit_compare(arr_res.bits, arr1.bits, 12) == -1) {
      ret = 1 + (s21_getSign(value_1) != s21_getSign(value_2));
    } else {
      s21_div28(arr1, arr2, &arr_res);
      s21_toDecimal(arr_res, result);
      s21_setSign(result, s21_getSign(value_1) != s21_getSign(value_2));
    }
  }
  return ret;
}

void s21_div28(s21_decimal value_1, s21_decimal value_2,
               s21_decimal *result) {
  s21_decimal min = {{0, 0, 0, 0}},
              max = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal left, left_pred, right, right_pred, middle, ans_tmp;

  s21_toDecimal28(min, &left);
  s21_toDecimal28(max, &right);

  s21_zeroArray(left_pred.bits, 12);
  s21_zeroArray(right_pred.bits, 12);

  while (s21_bit_compare(left_pred.bits, left.bits, 12) ||
         s21_bit_compare(right_pred.bits, right.bits, 12)) {
    s21_copyArray(left.bits, left_pred.bits, 12);
    s21_copyArray(right.bits, right_pred.bits, 12);
    s21_middle28(left, right, &middle);
    s21_mul28(middle, value_2, &ans_tmp);
    if (s21_bit_compare(ans_tmp.bits, value_1.bits, 12) == -1) {
      s21_copyArray(middle.bits, left.bits, 12);
    } else {
      s21_copyArray(middle.bits, right.bits, 12);
    }
  }
               }