#include "../s21_decimal.h"

int s21_get_scale(s21_decimal num) {
    int mask = 0b11111111; // 8 битов или 255 в десятичной
    mask <<= 16;
    mask = num.bits[3] & mask;
    mask >>= 16;
    return mask;
}