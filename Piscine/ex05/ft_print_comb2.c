#include<unistd.h>
void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_print_number(int n) {
    // Convert int to 2-digit character format
    ft_putchar('0' + n / 10);
    ft_putchar('0' + n % 10);
}
void	ft_print_comb2(void)
{

	  for (int i = 0; i <= 98; i++) {
 	       for (int j = i + 1; j <= 99; j++) {
        	    ft_print_number(i);
            	ft_putchar(' ');
        	    ft_print_number(j);

            // Don't print comma-space after last combination
            if (!(i == 98 && j == 99)) {
                ft_putchar(',');
                ft_putchar(' ');
            }
}}}
int main(void){


ft_print_comb2();

return 0;
}
