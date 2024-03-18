#include "s21_decimal.h"

void s21_decimal_filling(s21_decimal *num) {
    for (int i = 0; i < MAX_BLOCK_NUMBER; i++) {
        s21_set_bit(num, i, 1);
    }
}