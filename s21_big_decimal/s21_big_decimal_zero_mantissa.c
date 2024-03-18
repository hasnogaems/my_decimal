#include "../s21_decimal.h"
// обнуляем мантису биг децимал
void s21_big_decimal_zero_mantissa(s21_big_decimal *result) {
  for (int i = 0; i < 12; i++) {
    result->bits[i] = 0;
  }
}