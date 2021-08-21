/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:03:33 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/21 17:54:50 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isnumber(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	ft_error_check(int i, char **str)
{
	if (i != 3 || *str[2] == 0)
	{
		write(1, "parameters intake: ./client <server_pid> <string>\n", 40);
		return (0);
	}
	else if (!ft_isnumber(str[1]))
	{
		write(1, "your entered pid is not valid\n", 40);
		return (0);
	}
	else
		return (1);
}

static void	ft_send_nl(int pid)
{
	kill(pid, SIGUSR2);
	usleep(40);
	kill(pid, SIGUSR2);
	usleep(40);
	kill(pid, SIGUSR2);
	usleep(40);
	kill(pid, SIGUSR2);
	usleep(40);
	kill(pid, SIGUSR1);
	usleep(40);
	kill(pid, SIGUSR2);
	usleep(40);
	kill(pid, SIGUSR1);
	usleep(40);
	kill(pid, SIGUSR2);
}

static void	ft_send_str(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 7;
		while (i >= 0)
		{
			if (str[j] & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(35);
		}
		j++;
	}
	ft_send_nl(pid);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	if (!ft_error_check(argc, argv))
		return (0);
	ft_send_str(server_pid, argv[2]);
	return (0);
}
