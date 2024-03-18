#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_arithmetic_result result_num = S21_ARITHMETIC_OK;
    if (!result) {
        // Если указатель на decimal является NULL
        result_num = S21_ARITHMETIC_ERROR;
    } 
    /* .... */

    return result_num;
}
