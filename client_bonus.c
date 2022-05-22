/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:46:07 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/22 21:06:49 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_hand_error(0);
}

void	ft_send_byte(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(900);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		len;

	if (argc != 3)
	{
		if (argc == 2 && !ft_atoi(argv[1]))
			ft_hand_error(3);
		ft_hand_error(argc);
	}
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	signal(SIGUSR1, ft_handler);
	i = -1;
	while (++i <= len)
		ft_send_byte(pid, argv[2][i]);
}
