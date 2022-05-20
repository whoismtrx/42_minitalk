/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:46:07 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/20 01:47:09 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Done!!\n", 1);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		j;
	int		len;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	signal(SIGUSR1, ft_handler);
	i = 0;
	while (i <= len)
	{
		j = 0;
		while (j < 8)
		{
			if ((argv[2][i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(900);
		}
		i++;
	}
}
