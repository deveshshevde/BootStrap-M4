// #include "../source/status.h"

#include "printf.h"



/*
 TODO: READ FIRST 
 When you pass arguments to a function, they are typically placed on the stack or in CPU registers
(depending on the platform and the calling convention being used). The way in which these arguments
are laid out in memory, and the order in which they are passed, is defined by the ABI 
(Application Binary Interface) of the platform.
To ensure proper alignment and compatibility with the ABI, the va_arg macro performs some type promotion 
internally, based on the type specified as a parameter to the macro. 
Specifically, if the type specified is a smaller integer type (such as char or short),
it will be promoted to int.
registers, which can cause performance issues or even crashes on some platforms.
 By promoting these types to int, which is typically properly aligned, the va_arg macro ensures that
 the arguments are handled correctly and compatibleThe reason for this promotion is that smaller
  integer types may not be properly aligned on the stack or in CPU
*/

/*
**ABI BASIC RULES** 

-  A subroutine must preserve the content of R4-R11 and Stack pointer
-   Argument must be passed through R0-R3
-   For more args we can give pointer to the memrory
-   ret urn value in r0 , r0-r1 if it is 64bit

*/

extern int _write(int file, const char *ptr, int len);
u32 custom_print(const char* f , ...)
{
    va_list arg_pointer;
    u32 counter = 0;
    va_start(arg_pointer, f);
    while (*f != '\0')  
    {
     if(*f == '%'){
        counter += format_print(*(++f),arg_pointer); // count the number of char character written
     }   
     else{
        counter += _write(1, f, 1);
        ++f;
     }
    }
    va_end(arg_pointer);
    return counter;
}


u32 format_print(const char c, va_list arg_pointer){

 u32 counter = 0;
 if(c == 'c')// means we encounter the c in the printf args
 { 
    char_print(va_arg(arg_pointer, int));
    counter += 1;
 }
 else if(c == 's')
 {
    str_print(va_arg(arg_pointer, char*));
    counter += 1;
 }
 else if(c=='d')
 {
    digit_print(va_arg(arg_pointer, int) , 10);
    counter += 1;
 }
 else
 {
    counter += _write(1, &c, 1);
    counter += 1;
 }
 return counter;
}

void char_print(int c){
    _write(1, (const char *)&c, 1);
}
void str_print(char* str){
    int counter = 0;
    while(str[counter] != '\0'){
        _write(1, &str[counter], 1);
        ++counter;
    }
}
void digit_print(long num ,int base){
    u32 counter = 0;
    char *symbols = "0123456789ABCDEF";
    if(num < 0){
        _write(1, "-", 1);
        digit_print(-num , base);
        counter++;
    }
    else if(num<base)
    {
        return char_print(symbols[num]);  
    }
    else
    {
        digit_print(num/base, base);
        digit_print(num%base, base);
        counter++;        
    }
    
}