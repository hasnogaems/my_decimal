#include "../s21_decimal.h"
int bits_zero_check(const unsigned *arr, int count) {
  int ret = 1;
  for (int i = 0; i < count && ret; i++) {
    ret = arr[i] == 0;
  }
  return ret;
}