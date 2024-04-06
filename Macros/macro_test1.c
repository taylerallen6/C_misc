#include <stdio.h>


#define MACRO_VARIABLE 4239

#define TYPE int

struct My_struct
{
    TYPE value;
} typedef My_struct;


int main()
{
    TYPE var = 5;
    printf("hello\n");
    printf("%d\n", MACRO_VARIABLE);
    printf("%d\n", var);


    My_struct struct1 = {23};
    printf("%d\n", struct1.value);


    return 0;
}