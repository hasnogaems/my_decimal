#include "../s21_decimal.h"
// больше ли биг децимал
int s21_big_decimal_is_greater(s21_big_decimal value_1, s21_big_decimal value_2){
    int result = 0, out = 0;
    for (int i = 7; i >= 0 && !result && !out; i--) {
        if (value_1.bits[i] || value_2.bits[i]) {
            if (value_1.bits[i] > value_2.bits[i]) {
                result = 1;
            }
            if (value_1.bits[i] != value_2.bits[i]) {
                out = 1;
            }
        }
    }
    return result;

}

// int main() {
//     s21_big_decimal value_1 = {{0, 1, 0, 0, 1, 0, 0, 1}};
//     s21_big_decimal value_2 = {{0, 0, 1, 1, 0, 0, 1, 1}};

//     if (s21_big_decimal_is_greater(value_1, value_2)) {
//         printf("Number 1 is greater than Number 2\n");
//     } else {
//         printf("Number 2 is greater than or equal to Number 1\n");
//     }

//     return 0;
// }
