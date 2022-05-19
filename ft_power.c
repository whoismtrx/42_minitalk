#include "minitalk.h"

#include <unistd.h>

int	ft_power(int nb, int power)
{
	int	n;

	n = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 0 && nb == 0)
		return (1);
	while (power-- > 0)
		n = n * nb;
	return (n);
}