#include "../s21_decimal.h"
void s21_copy_array(const unsigned *array1, unsigned *array2, int count) {
  for (int i = 0; i < count; ++i) {
    array2[i] = array1[i];
  }
}