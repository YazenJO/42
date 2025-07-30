#include <unistd.h>
void  ft_print_numbers(){
		for(int i=0;i<=9;i++)
		{
			char num='0'+i;
			write(1,&num,1);
		}





}
int main(){
	ft_print_numbers();





return 0;
}
