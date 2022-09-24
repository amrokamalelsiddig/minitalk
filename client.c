/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:25:43 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/09/24 17:02:44 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void	send_char(int pid, char x)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if ((x << i) & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(2500);
	}
}

int	main(int ARGC, char **ARGV)
{
	int	n;
	int	pid ;

	pid = atoi(ARGV[1]);
	n = 0;
	if (!(pid) || !(ARGV[2]) || pid < 100)
	{
		printf("Error\n");
		return (0);
	}
	while (ARGV[2][n])
	{
		send_char(pid, ARGV[2][n]);
		n++;
	}
	return (0);
}
