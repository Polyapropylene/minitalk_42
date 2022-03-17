#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	t;
	int			minus;

	i = 0;
	t = 0;
	minus = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		t = (t * 10) + ((str[i]) - '0');
		if (minus * t > 2147483647)
			return (-1);
		if (minus * t < -2147483648)
			return (0);
		i++;
	}
	return (t * minus);
}