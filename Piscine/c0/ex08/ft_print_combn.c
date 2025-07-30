#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void printarr(char *arr,int n){
	 for (int i = 0; i < n; i++)
        ft_putchar(arr[i]);
	//is it the last comb (check the first digit if it equals the first max digit)
    if (arr[0] != ('9' - n + 1 + '0')) {
        ft_putchar(',');
        ft_putchar(' ');
    }
}
	
void generate_comb(int n,char start,int postion,char *arr){
	if(postion==n){
	 printarr(arr,n);

	return;
	}


	for(char i=start;i<='9';i++){
	
	arr[postion]=i;
	generate_comb(n,i+1,postion+1,arr);
	}



}
void ft_print_combn(int n){
int postion=0;
char Com[2];
char start='0';
 generate_comb(n,start,postion,Com);

	




}

int main(void){
 ft_print_combn(4);






return 0;
}
