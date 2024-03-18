#include "../s21_decimal.h"

void s21_big_decimal_div10(unsigned *arr, int count) {
  unsigned long long int mod = 0;
  for (int i = count - 1; i >= 0; i--) {
    unsigned long long int tmp = mod << 32;
    tmp += arr[i];
    arr[i] = tmp / 10;
    mod = tmp % 10;
  }
}
