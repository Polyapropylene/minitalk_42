#include "minitalk.h"

void	send_message(int pid, char *bits)
{
	int i;

	i = 0;
	while(bits[i] != '\0')
	{
		if(bits[i] == '1')
			kill(pid, SIGUSR1);
		if(bits[i] == '0')
			kill(pid, SIGUSR2);
		i++;
	}
}

char	*convert_to_bits(char *str)
{
	size_t	i;
	char	*converted;

	i = ft_strlen(str);
	converted = malloc(i * 8 * sizeof(char) + 1);
	while (i >= 0)
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