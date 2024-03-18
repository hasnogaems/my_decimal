#include "../s21_decimal.h"

int s21_get_bit(s21_decimal num, int index) { // num - число в котором хранится битовое представление index - индекс бита, значение которого надо получить
    int value;
    if ((num.bits[index / 32] & (1 << index % 32)) == 0) { // 32 бита - размер int, определяем какому элементу массива соответсвует бит, смещением (остаток от деления) находим позицию бита
       value = 0;
    } else {
    value = 1;
    }
}


bool get_bit_value(s21_decimal target, int bit_number) {
  int index = 0;
  while (bit_number >= 32) {
    index++;
    bit_number -= 32;
  }

  bool x = 1 << bit_number & target.bits[index];
  return x;
}
