#include <unistd.h>
 void ft_print_reverse_alphabet (){
		char	letter;

	letter = 'z';

	//while letter is less than or equal to z
	while (letter >= 'a')
	{
		//print letter
		write(1, &letter, 1);

		//go to next letter
		letter--;
	}}
int main(void){
ft_print_reverse_alphabet ();



return 0;
}
