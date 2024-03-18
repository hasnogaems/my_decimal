#include "../s21_decimal.h"
// полное обнуление big decimal
void s21_big_decimal_is_zero(s21_big_decimal *result) {
    s21_big_decimal_zero_mantissa(result);
 
}