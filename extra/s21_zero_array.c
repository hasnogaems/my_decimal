#include "../s21_decimal.h"
void s21_zero_array(unsigned *array, int count) {
  for (int i = 0; i < count; ++i) {
    array[i] = 0;
  }
}