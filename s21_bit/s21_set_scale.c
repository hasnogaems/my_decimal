#include "../s21_decimal.h"

int s21_set_scale(s21_decimal* num, int scale) {
    int result = 0;
  if (scale < 256 && scale >= 0) { // масштаб от 0 до 255 correctly
    for (int i = 0; i < 8; i++) { // 8 бит для масштаба 
      set_bit(num, i + MAX_BLOCK_BITS / 2  + MAX_BLOCK_NUMBER, scale % 2);
      scale >>= 1;
    }
  } else result = 1;
  return result;

}