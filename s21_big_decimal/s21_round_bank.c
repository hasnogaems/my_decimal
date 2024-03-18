#include "../s21_decimal.h"

int s21_round_bank(s21_big_decimal *big_value, int mod, int *newScale) {
  int ret = !s21_decimal_is_zero(big_value->bits + 3, 9);
  if (!ret && (mod > 5 || (mod == 5 && (big_value->bits[0] & 1)))) {
    // проверяем краевые значения (на переполнения)
    unsigned max_mantisa[] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
    if (!s21_bit_compare(big_value->bits, max_mantisa, 3)) {
      if (*newScale > 0) {
        mod = s21_big_decimal_mod10(big_value->bits, 12);
        s21_big_decimal_div10(big_value->bits, 12);
        (*newScale)--;
      } else {
        ret = 1;
      }
    }
    s21_big_decimal one;
    s21_zero_s21_decimal(one.bits, 12);
    one.bits[0] = 1;
    s21_big_decimal_add(*big_value, one, big_value);
  }
  return ret;
}
