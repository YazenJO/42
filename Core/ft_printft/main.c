
#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
   
    ft_printf("|%-55df|\n", 42);
    ft_printf("|%-3d|\n", 42);
    printf("|%-55x|\n", 42);
    ///ft_printf("|%02d|\n", 1);
    //ft_printf("|%0d|\n", 42);
    return 0;
}