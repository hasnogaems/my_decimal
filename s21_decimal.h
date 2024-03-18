#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_NAN (0.0 / 0.0)
#define S21_INFINITY (1.0 / 0.0)
#define S21_NULL ((void*)0)
#define MAX_BITS 128
#define MAX_BLOCK_BITS 32
#define MAX_BLOCK_NUMBER 96
#define MAX_DECIMAL 79228162514264337593543950335.L

typedef struct {
 int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[12];  // мантисса
     // первая единица справа
} s21_big_decimal;

typedef enum s21_decimal_sign {
  S21_POSITIVE = 0,
  S21_NEGATIVE = 1
} s21_decimal_sign;

typedef enum s21_arithmetic_result {
  S21_ARITHMETIC_OK = 0,
  S21_ARITHMETIC_BIG = 1,
  S21_ARITHMETIC_SMALL = 2,
  S21_ARITHMETIC_ZERO_DIV = 3,
  S21_ARITHMETIC_ERROR = 4
} s21_arithmetic_result;

typedef enum s21_comparison_result {
  S21_COMPARISON_FALSE = 0,
  S21_COMPARISON_TRUE = 1,
} s21_comparison_result;

typedef enum s21_conversion_result {
  S21_CONVERSION_OK = 0,
  S21_CONVERSION_ERROR = 1
} s21_conversion_result;

typedef enum s21_other_result {
  S21_OTHER_OK = 0,
  S21_OTHER_ERROR = 1
} s21_other_result;

void s21_big_decimal_zero_mantissa(s21_big_decimal* result);  
void s21_big_decimal_is_zero(s21_big_decimal* result);        
int is_greater_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2);  

void s21_copy_decimal(const unsigned* array1, unsigned* array2, int count); 
void s21_zero_s21_decimal(unsigned* array, int count);                       
void s21_big_decimal_mul_10(unsigned* arr, int count);                       
int s21_decimal_is_zero(const unsigned* arr, int count);
int s21_round_bank(s21_big_decimal* big_value, int mod, int* newScale);
void s21_big_decimal_add(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal* result);
void s21_big_decimal_div10(unsigned* arr, int count);
int s21_big_decimal_mod10(const unsigned* arr, int count);
void normalize_big(s21_big_decimal* big_value_1, s21_big_decimal* big_value_2);
int multiply_10_mantis_big(s21_big_decimal* big_value, int def);
void zeroes_left_big(s21_big_decimal* big_value);
int compare_mantis_big(s21_big_decimal* big_value_1,
                       s21_big_decimal* big_value_2);
int multiply_mantis_big(s21_big_decimal big_value_1,
                        s21_big_decimal* big_value_2, s21_big_decimal* result);
void s21_decimal_to_s21_big_decimal(s21_decimal value,
                                    s21_big_decimal* big_value);
int s21_big_decimal_to_s21_decimal(s21_big_decimal big_value,
                                   s21_decimal* value);
void s21_big_decimal_to_s21_decimal_95(s21_big_decimal* big_result,
                                       s21_decimal* result);
int sum_mantissa(s21_big_decimal* big_value_1, s21_big_decimal* big_value_2,
                 s21_big_decimal* result);
void sub_mantis_big(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal* result);
void s21_set_bit_big(s21_big_decimal* num, int bit, int result);
int s21_get_bit_big(s21_big_decimal* num, int index);
void print_big_decimal(s21_big_decimal* num);
int shift_left_big(s21_big_decimal* big_value, int index);
void init_big(s21_decimal value, s21_big_decimal* dec);
int div_big(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal* result);
void div_10_big_decimal(s21_big_decimal* dst, int n);
int preparation_big_decimal(s21_big_decimal* result, int scale);
int is_zero_big_decimal(s21_big_decimal dec);
int is_greater_or_equal_big_decimal(s21_big_decimal value_1,
                                    s21_big_decimal value_2);
void division(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal* result);
unsigned int division_with_rest_for10(s21_big_decimal value_1,
                                      s21_big_decimal* result);
int go_beyond_big_decimal_s21(s21_big_decimal* dec);
int is_equal_big_decimal(s21_big_decimal* value_1, s21_big_decimal* value_2);

void s21_clear_decimal(s21_decimal* num);  
int s21_is_zero(s21_decimal num);                          
void s21_set_sign(s21_decimal* num, int sign);             
int s21_get_sign(s21_decimal num);                        
int s21_s21_get_bit(s21_decimal num, int index);               
void s21_set_bit(s21_decimal* num, int index, int value);  
int s21_get_scale(s21_decimal num);                        
int s21_set_scale(s21_decimal* num, int scale);            
void s21_decimal_filling(s21_decimal* num);                

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

//////// ДОП ФУНКЦИИ АРИФМЕТИКА ///////

void s21_add_big_decimal(s21_big_decimal big_value_1,
                         s21_big_decimal big_value_2, s21_big_decimal* result);
void s21_sub_big_decimal(s21_big_decimal big_value_1,
                         s21_big_decimal big_value_2, s21_big_decimal* result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_zero(const unsigned *arr, int count);
int s21_bit_compare(const unsigned *arr_1, const unsigned *arr_2, int count);

int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);
int bits_zero_check(const unsigned *arr, int count);
void s21_div_big(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result) ;
               void s21_mul_big(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result) ;
void s21_set_bit(s21_decimal* num, int index, int value);
int s21_get_bit(s21_decimal num, int index);
void s21_div10(unsigned *arr, int count);
void s21_zero_array(unsigned *array, int count);
void s21_middle_big(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result);
                  void s21_copy_array(const unsigned *array1, unsigned *array2, int count) ;
                  void s21_zero_array(unsigned *array, int count) ;
                  void nullify(s21_decimal *d) ;
                  void printb(s21_decimal bits_array);
bool get_bit_value(s21_decimal target, int bit_number);
#endif
