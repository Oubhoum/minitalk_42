/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:29:43 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/03/08 14:18:40 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	handler(int s, siginfo_t *info, void *useless)
{
	static char	byte;
	static int	i;
	static int	check_pid;

	(void)useless;
	if (check_pid != info->si_pid)
	{
		check_pid = info->si_pid;
		byte = '\0';
		i = 0;
	}
	if (s == SIGUSR1)
		byte = byte | (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(byte, 1);
		byte = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
