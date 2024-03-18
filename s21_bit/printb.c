#include "../s21_decimal.h"
void printb(s21_decimal bits_array) {
 int bit_number;
 printf("[");
 
  bit_number = 127;
  while (bit_number > 95) {
    printf("%d", get_bit_value(bits_array, bit_number));
    bit_number--;
    if ((((bit_number + 1) % 4) == 0) && (bit_number != 95)) {
      printf(".");
    }
  }
  printf("] ");
   printf("] [");
  bit_number = 95;
  while (bit_number > 63) {
    printf("%d", get_bit_value(bits_array, bit_number));
    bit_number--;
    if ((((bit_number + 1) % 4) == 0) && (bit_number != 63)) {
      printf(".");
    }
  }
  printf("] [");
 
  bit_number = 63;
  while (bit_number > 31) {
    printf("%d", get_bit_value(bits_array, bit_number));
    bit_number--;
    // if(((bit_number+1)%4)==0&&bit_number!=-1){
    // printf(".");}
    if ((((bit_number + 1) % 4) == 0) && (bit_number != 31)) {
      printf(".");
    }
  }
 
 
    bit_number = 31;
  printf("] [");
  while (bit_number >= 0) {
    printf("%d", get_bit_value(bits_array, bit_number));
    bit_number--;
    if ((((bit_number + 1) % 4) == 0) && (bit_number != -1)) {
      printf(".");
    }
  }
  printf("]");

  printf("\n");
}
