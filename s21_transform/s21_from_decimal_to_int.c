#include "../s21_decimal.h"

// int s21_from_decimal_to_int(s21_decimal src, int *dst) {
//     s21_conversion_result result_num = S21_CONVERSION_OK;
//     if (!dst) {
//         // Если указатель на int является NULL
//         result_num = S21_CONVERSION_ERROR;
//     } else {
//         *dst = 0;
//         *dst = src.bits[0];
//         *dst = *dst * ((src.bits[3] >> 31) & 1 ? -1 : 1);
//     ret = 0;
//     }
//     /* ...... */
    
//     return result_num;
// }

// int s21_from_decimal_to_int(s21_decimal src, int *dst) {
//   int ret = 1;
//   if (*dst == 0) {
//     *dst = src.bits[0];
//     *dst = *dst * ((src.bits[3] >> 31) & 1 ? -1 : 1);
//     ret = 0;
//   }
//   return ret;
// }
