#include "minitalk.h"
#include <stdio.h>
#include <string.h>

int send_null(int pid)
{
	static int i;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		++i;
		return (0);
	}
	return (1);
}

int	handle_message(char *ostr, int opid)
{
	static int	i;
	static int	bit;
	static char *str;
	static int	pid;

	if (ostr)
		str = ft_strdup(ostr);
	if (opid)
		pid = opid;
	
	while (str[i])
	{
		while (bit < BYTE_SIZE)
		{
			if (str[i] & (0x80 >> bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			return (0);
		}
		i++;
		bit = 0;
	}
	
	return (send_null(pid));
}

void	client_handler(int signum, siginfo_t *info, void *kek)
{
	(void) kek;
	(void) info;
	if (signum == SIGUSR1)
	{
		if (handle_message(0, 0) == 1)
		{
			write(1,"Message recieved!\n",19);
			exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	t_sigaction	sa_signal;

	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = client_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);
		handle_message(argv[2], pid);
	}
	else
		ft_printf("Wrong number of arguments!");
	while (1)
		pause();
	return (0);
}