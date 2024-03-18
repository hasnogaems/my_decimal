#include "../s21_decimal.h"

int s21_bit_compare(const unsigned *arr_1, const unsigned *arr_2, int count) {
  int ret = 0;
  for (int i = count - 1; i >= 0 && !ret; i--) {
    if (arr_1[i] != arr_2[i]) {
      ret = arr_1[i] > arr_2[i] ? 1 : -1;
    }
  }
  return ret;
}