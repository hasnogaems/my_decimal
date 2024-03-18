#include "../s21_decimal.h"

void s21_big_decimal_mul_10(unsigned *arr, int count) {
  unsigned long long int overflow = 0;
  for (int k = 0; k < count; ++k) {
    unsigned long long int tmp = arr[k];
    tmp *= 10;
    tmp += overflow;
    arr[k] = tmp & 0xFFFFFFFF;
    overflow = tmp >> 32;
  }
}