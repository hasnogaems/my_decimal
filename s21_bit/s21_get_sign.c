#include "../s21_decimal.h"

int s21_get_sign(s21_decimal num) {
    return (s21_decimal_sign)get_bit(num, 127);
    /* 127 является последним битом в числе и используется 
    для хранения знака числа */
}
