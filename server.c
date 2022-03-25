#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *kek)
{
	static int	b;
	static char	c;

	(void) kek;
	if (b == 0)
		c = 0xFF;
	if (signum == SIGUSR1)
		c |= 0x80 >> b;
	else if (signum == SIGUSR2)
		c ^= 0x80 >> b;
	b++;
	if (b == 8)
	{
		if (c)
			write(1, &c, 1);
		b = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	ft_printf("Server pid : %d\n", getpid());
	t_sigaction	sa_signal;

	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
	{
		pause();
	}	
	return (0);
}