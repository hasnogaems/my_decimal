#include "../s21_decimal.h"
// полное обнуление big decimal
void s21_big_decimal_is_zero(s21_big_decimal *result) {
    s21_big_decimal_zero_mantissa(result);
    result->exponenta = 0;
    result->negative = 0;
    result->one_position_left = 0;
    result->one_right = 0;
    result->zero_left = 0;
}