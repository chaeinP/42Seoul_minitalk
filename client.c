/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:18:01 by chaepark          #+#    #+#             */
/*   Updated: 2022/04/28 00:31:40 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	sendMessage(int pid, char c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		usleep(100);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;

	if (argc != 3)
		ft_putstr("Bad Request, Invalid Parameters");
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		if (sendMessage(server_pid, *message) == 0)
		{
			ft_putstr("error");
			return (0);
		}
		message++;
	}
	sendMessage(server_pid, '\0');
}
