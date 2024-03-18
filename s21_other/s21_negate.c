#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
    s21_other_result result_num = S21_OTHER_OK;
     if (result == NULL) {
    result_num = S21_OTHER_ERROR;
  } else {
    nullify(result);
    int sign=0;
    sign = s21_get_sign(value);
    *result = value;
    if (sign == 1) {
      s21_set_sign(result, 0);
    } else {
      s21_set_sign(result, 1);
    }
  }
    /* ...... */
    
    return result_num;
}