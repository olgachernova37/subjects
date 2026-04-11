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
    int a = ft_factor();
    int b;
    while(*s=='*')
    {
        s++;
        b = ft_factor;
        a = a * b;

    }
    return (a);
}

int ft_sum()
{
    int sum1 = ft_product();
    int sum2;
    while(*s =='+')
    {
        s++;
        sum2 = ft_product;
        sum1 = sum2 + sum1;
    }
    return (sum1);
}

int ft_factor()
{
    int n = 0;
    if(isdigit(*s))
        return (*s++ - '0');
    while(*s=='(')
    {
        s++;
        n = ft_sum;
        s++;
    }
    return (n);
}

int check_input(char *str)
    {
        int par = 0;
        int i = 0;
    }
