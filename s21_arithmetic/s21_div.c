#include "../s21_decimal.h"
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = bits_zero_check(value_2.bits, 3) ? 3 : 0;
  if (!ret) {
    s21_decimal max_num = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_big_decimal arr1, arr2, arr_max, arr_res;

    s21_decimal_to_s21_big_decimal(value_1, &arr1);
    s21_decimal_to_s21_big_decimal(value_2, &arr2);
    s21_decimal_to_s21_big_decimal(max_num, &arr_max);
    s21_mul_big(arr2, arr_max, &arr_res);
    if (s21_bit_compare(arr_res.bits, arr1.bits, 12) == -1) {
      ret = 1 + (s21_get_sign(value_1) != s21_get_sign(value_2));
    } else {
      s21_div_big(arr1, arr2, &arr_res);
      s21_big_decimal_to_s21_decimal(arr_res, result);
      s21_set_sign(result, s21_get_sign(value_1) != s21_get_sign(value_2));
    }
  }
  return ret;
}

void s21_div_big(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result) {
  s21_decimal min = {{0, 0, 0, 0}},
              max = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_big_decimal left, left_pred, right, right_pred, middle, ans_tmp;

  s21_decimal_to_s21_big_decimal(min, &left);
  s21_decimal_to_s21_big_decimal(max, &right);

  s21_zero_array(left_pred.bits, 12);
  s21_zero_array(right_pred.bits, 12);

  while (s21_bit_compare(left_pred.bits, left.bits, 12) ||
         s21_bit_compare(right_pred.bits, right.bits, 12)) {
   s21_copy_array(left.bits, left_pred.bits, 12);
   s21_copy_array(right.bits, right_pred.bits, 12);
    s21_middle_big(left, right, &middle);
    s21_mul_big(middle, value_2, &ans_tmp);
    if (s21_bit_compare(ans_tmp.bits, value_1.bits, 12) == -1) {
     s21_copy_array(middle.bits, left.bits, 12);
    } else {
     s21_copy_array(middle.bits, right.bits, 12);
    }
  }
               }

               void s21_div10(unsigned *arr, int count) {
  unsigned long long int mod = 0;
  for (int i = count - 1; i >= 0; i--) {
    // printf("%08X ", arr[i]);
    unsigned long long int tmp = mod << 32;
    tmp += arr[i];
    arr[i] = tmp / 10;
    mod = tmp % 10;
  }
  // printf("\n");
}

void s21_middle_big(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result) {
  s21_big_decimal_add(value_1, value_2, result);
  unsigned mod = 0;
  for (int i = 11; i >= 0; --i) {
    unsigned tmp = mod;
    mod = result->bits[i] & 1;
    result->bits[i] = (result->bits[i] >> 1) | (tmp << 31);
  }
}