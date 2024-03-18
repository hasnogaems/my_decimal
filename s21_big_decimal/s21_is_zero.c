#include "../s21_decimal.h"

// проверяет на ноль s21_decimal

int s21_is_zero(s21_decimal num) {
  int result = 0;
  for (int i = 2; i >= 0; i--) { // биты же доступны по индексам от 0 до 2 (все число хранится в массиве из 3 битов)
    if (num.bits[i] != 0) { // проверка значения текущего бита, если оно не равно 0 то присваивается значение 1
      result = 1;
      break;
    }
  }
  return result;
}