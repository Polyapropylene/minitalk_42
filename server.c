#include "minitalk.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server pid : %d\n", pid);
	return (0);
}