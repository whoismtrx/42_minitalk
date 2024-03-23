/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:49:01 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/22 21:07:14 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_reset(int *c, int *p, int *b)
{
	*c = 0;
	*p = 0;
	*b = 0;
}

void	ft_handler(int signal, siginfo_t *info, void *ptr)
{
	static int	c;
	static int	p;
	static int	pid;
	static int	b;

	ptr = NULL;
	if (pid != info->si_pid)
		ft_reset(&c, &p, &b);
	pid = info->si_pid;
	if (signal == SIGUSR1)
		c += ft_power(2, p);
	p++;
	if (p == 8)
	{
		if (c > 0)
			b = 1;
		ft_putchar_fd(c, 1);
		if (c == '\0' && b)
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		p = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
