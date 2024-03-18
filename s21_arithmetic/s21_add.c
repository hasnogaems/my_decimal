#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_arithmetic_result result_num = S21_ARITHMETIC_OK;
    if (!result) {
        result_num = S21_ARITHMETIC_ERROR;
    } else if (s21_get_sign(value_1) == s21_get_sign(value_2)) {
        s21_big_decimal big_1, big_2, result_big;
        s21_decimal_to_s21_big_decimal(value_1, &big_1);
        s21_decimal_to_s21_big_decimal(value_2, &big_2);
        s21_big_decimal_add(big_1, big_2, &result_big);
        result_num = s21_big_decimal_to_s21_decimal(result_big, result);
        s21_set_sign(result, s21_get_sign(value_1));
        if (result_num) result_num += s21_get_sign(value_1);
    } else {
        if (s21_get_sign(value_2)) {
            s21_negate(value_2, &value_2);
            result_num = s21_sub(value_1, value_2, result);
        } else {
            s21_negate(value_1, &value_1);
            result_num = s21_sub(value_2, value_1, result);
        }
    }
    return result_num;
}