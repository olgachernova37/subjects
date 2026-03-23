#include "test.h"

char *s;

void unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n",c);
    else
        printf("Unexpected end of file\n");
}

int ft_product()
{
    int a=ft_factor();
    int b;
    while(*s == '*')
    {
        
    }
}