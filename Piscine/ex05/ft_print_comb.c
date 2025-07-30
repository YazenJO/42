#include <unistd.h>
void	ft_print(char fst, char snd, char trd)
{
	write(1, &fst, 1);
	write(1, &snd, 1);
	write(1, &trd, 1);

	//If not the numbers 789 the comma is printed
	if (!(fst == '7' && snd == '8' && trd == '9'))
		write(1, ", ", 2);
}
void	ft_print_comb(void)
{
	char	fst;
	char	snd;
	char	trd;

	// The numbers won't be repeated because
	// they are the sum of the previous plus one
	fst = '0';
	while (fst <= '7')
	{
		snd = fst + 1;
		while (snd <= '8')
		{
			trd = snd + 1;
			while (trd <= '9')
			{	
				//Send the numbers to be printed
				ft_print(fst, snd, trd);
				trd++;
			}
			snd++;
		}
		fst++;
	}
}
int	main(void)
{
	ft_print_comb();




return 0;
}
