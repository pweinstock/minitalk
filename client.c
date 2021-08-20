/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:03:33 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/20 17:53:33 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int i;
	int j;
	int pid;

	argc = 0;
	j = 0;
	pid = ft_atoi(argv[1]);

	while (argv[2][j])
	{
		i = 7;
		while (i >= 0)
		{
			if (argv[2][j] & (1 << i))
			{
				write(1, "1", 1);
				kill(pid, SIGUSR1);
			}
			else
			{
				write(1, "0", 1);
				kill(pid, SIGUSR2);
			}
			i--;
			usleep(100);
		}
		j++;
	}
	write(1, "\n", 1);
}