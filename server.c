/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:18:09 by chaepark          #+#    #+#             */
/*   Updated: 2022/04/28 00:45:02 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signal, siginfo_t *siginfo, void *none)
{
	static unsigned int	result;
	static unsigned int	digit;
	static pid_t		pid;

	(void)none;
	pid = siginfo->si_pid;
	result |= (signal == SIGUSR1);
	if (++digit < 8)
	{
		result <<= 1;
		return ;
	}
	digit = 0;
	if (result != '\0')
	{
		ft_putchar(result);
		result = 0;
		return ;
	}
	ft_putchar('\n');
	result = 0;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_putstr("server_pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
