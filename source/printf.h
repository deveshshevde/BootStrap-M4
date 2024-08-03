#pragma once

#include "inc/stdarg.h"
typedef unsigned int u32 ;

u32 custom_print(const char* f , ...);
u32 format_print(char c, va_list arg_pointer);
void char_print(int c);
void str_print(char* str);
void digit_print( int num);