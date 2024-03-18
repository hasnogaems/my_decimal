#include "../s21_decimal.h"

int s21_zero(const unsigned *arr, int count) {
  int ret = 1;
  for (int i = 0; i < count && ret; i++) {
    ret = arr[i] == 0;
  }
  return ret;
}