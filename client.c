#include "minitalk.h"

int main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		j;

	if(argc <= 1 || argc > 3)
		return (0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while(argv[2][i])
	{
		j = 0;
		while (j < 8)
		{
			if ((argv[2][i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(1000);
		}
		i++;
	}
}