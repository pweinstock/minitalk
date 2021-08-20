/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:52:14 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/20 17:37:16 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	power(int base, int exp)
{
	int	result;

	result = 1;
	while (exp)
	{
		result *= base;
		exp--;
	}
	return (result);
}

static void	handler(int num)
{
	static int	binary = 0;
	static int	bits = 7;

	if (bits >= 0)
	{
		if (num == SIGUSR1)
			binary += power(2, bits);
		bits--;
	}
	if (bits < 0)
	{
		write(1, &binary, 1);
		binary = 0;
		bits = 7;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}