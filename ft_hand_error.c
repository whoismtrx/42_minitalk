/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hand_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 04:21:18 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/22 20:11:47 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_hand_error(int x)
{
	if (x == 1)
		ft_putstr_fd("Where is the PID 🤔", 2);
	if (x == 2)
		ft_putstr_fd("The message will not be written by itself 🙄", 2);
	if (x == 3)
		ft_putstr_fd("Wrong PID 😪", 2);
	if (x == 0)
		ft_putstr_fd("Done ✅", 1);
	if (x >= 4)
		ft_putstr_fd("Wa 3aya9ty 🤬", 2);
}
