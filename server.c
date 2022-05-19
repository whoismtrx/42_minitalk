#include "minitalk.h"

void	ft_handler(int x)
{
	static	int c;
	static	int p;

	if (x == SIGUSR1)
	{
		c += ft_power(2, p);
		p++;
	}
	else if(x == SIGUSR2)
		p++;
	if (p == 8)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		p = 0;
		c = 0;
	}
}

int main(void)
{
	int	pid;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1);
}