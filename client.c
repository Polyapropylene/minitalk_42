#include "minitalk.h"

void	send_message(int pid, cha )
{

}

char	*convert_to_bits(char *str)
{
	size_t	i;
	char	*converted;
	int		bit;

	i = ft_strlen(str);
	converted = malloc(i * 8 * sizeof(char) + 1);
	bit = 8;
	while ()
	{
	}
	return (converted);

}

int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);
		bits = convert_to_bits(argv[2]);
	}
	else
		ft_printf("Wrong number of arguments!");
		return (0);
}