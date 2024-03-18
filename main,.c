
#include "s21_decimal.h"
#include <stdio.h>
int main() {
  int a = 0b00000010001;
  int bitN = 33;
  // int result=get_bit_from_int(a, bitN);
  // printf("bit %d of %d is %d\n", bitN, a, get_bit_from_int(a, bitN));
  s21_decimal bits = {0b000001010, 0b0000000, 0b000101, 0b000000000000000000000000000000};
  // printf("decimal bit %d is %d", bitN, get_bit_value(bits, bitN));
 // set_bit_value(&bits, 32, 1); // howw toprintf in binary?????
  s21_decimal bits2 = {0b000000010, 0b0000000, 0b00000, 0b000000000000000000000000000};
  s21_decimal bits3 = {0b000000011, 0b0000110, 0b000101, 0b00000000000000000000011100000000};
   printb(bits3);
 // printb(bits);
 s21_div(bits, bits2, &bits3);
 // nullify(&bits);
 printb(bits3);
  return 0;
}

// multi_bit_check(...)

// 5 6 7 70 85
// i=& 1<<7
// i=1<<6
// i=i<<5
// 1>>7

// bits&mask

// int a = 11110111;
// int b = 00001011;

// unsigned int res = a(0) + b(0); // 1 + 1 = 2 -> 10

// unsigned int memo = res / 2 // 2 / 2 = 1

// unsigned int res = a(1) + b(1) + memo; // 1 + 1 + 1 = 3 -> 11

// unsigned int memo = res / 2 // 3 / 2 = 1













// i=0
// while(i>128){
// val1[0]
// }
// }



 