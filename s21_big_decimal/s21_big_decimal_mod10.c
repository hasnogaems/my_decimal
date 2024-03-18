#include "../s21_decimal.h"

int s21_big_decimal_mod10(const unsigned *arr, int count) {
  unsigned arrTmp[12];
  s21_copy_decimal(arr, arrTmp, 12);
  unsigned long long int mod = 0;
  for (int i = count - 1; i >= 0; i--) {
    unsigned long long int tmp = mod << 32;
    tmp += arrTmp[i];
    arrTmp[i] = tmp;
    mod = tmp % 10;
  }
  return mod;
}
