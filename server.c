#include "minitalk.h"

int main(int argc, char **argv)
{
	int	pid;

	if(argc < 1 && argv[0])
		return 0;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	// while (1)
	// {

	// }
}