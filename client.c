/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:25:51 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/03/08 14:21:10 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int	index;

	index = 0;
	if ((argc != 3) || (ft_atoi(argv[1]) <= 0))
		return (write(1, "error !\n", 9),
			exit(1), 0);
	while (argv[2][index])
	{
		i = 0;
		while (i < 8)
		{
			if (argv[2][index] & (1 << i))
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(800);
			i++;
		}
		index++;
	}
	return (0);
}
