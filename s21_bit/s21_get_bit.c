#include "../s21_decimal.h"

int s21_get_bit(s21_decimal num, int index) { // num - число в котором хранится битовое представление index - индекс бита, значение которого надо получить
    int index;
    if ((num.bits[index / 32] & (1 << index % 32)) == 0) { // 32 бита - размер int, определяем какому элементу массива соответсвует бит, смещением (остаток от деления) находим позицию бита
        index = 0;
    } else {
    index = 1;
    }
}