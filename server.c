/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:52:14 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/21 17:55:11 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*static int	power(int base, int exp)
{
	int	result;

	result = 1;
	while (exp)
	{
		result *= base;
		exp--;
	}
	return (result);
}*/

static int	power(int exp)
{
	if (exp == 0)
		return (1);
	else if (exp == 1)
		return (2);
	else if (exp == 2)
		return (4);
	else if (exp == 3)
		return (8);
	else if (exp == 4)
		return (16);
	else if (exp == 5)
		return (32);
	else if (exp == 6)
		return (64);
	else if (exp == 7)
		return (128);
	return (0);
}

static void	handler(int num)
{
	static int	binary = 0;
	static int	bits = 7;

	if (bits >= 0)
	{
		if (num == SIGUSR1)
			binary += power(bits); ///hard coden
		bits--;
	}
	if (bits < 0)
	{
		write(1, &binary, 1);
		if (binary == 4)
		{
			write(1, "\n", 1);
			
		}
		binary = 0;
		bits = 7;
	}
}

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	write(1, "server pid is: ", 15);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
