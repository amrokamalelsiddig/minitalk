/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:25:55 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/09/24 17:02:51 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	printf("Server Pid is : %d\n", getpid());
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
	{
		sleep(1);
	}
	return (0);
}

void	sighandler(int signum)
{
	static int	i;
	static char	ch;
	int			n;

	if (!i)
		i = 0;
	n = 0;
	if (signum == SIGUSR1)
	{
		ch = (ch << 1) | 1 ;
	}
	else if (signum == SIGUSR2)
		ch <<= 1;
	i++;
	if (i % 8 == 0)
	{
		write(1, &ch, 1);
		ch = 0;
	}
}
