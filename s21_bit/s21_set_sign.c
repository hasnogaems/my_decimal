#include "../s21_decimal.h"

void s21_set_sign(s21_decimal* num, int sign) {
    set_bit(num, 127, sign);
    /* 127 является последним битом в числе и используется 
    для хранения знака числа */
}