/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:25:55 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/20 19:27:48 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_init2(t_data *data)
{
    data->s_counter = 0;
    data->c_counter = 0;
}

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
	t_data data;

	ft_init2(&data);	
	if (!i)
		i = 0;
	if (signum == SIGUSR1)
		ch = (ch << 1) | 1 ;
	else if (signum == SIGUSR2)
		ch <<= 1;
	i++;
	if (i % 8 == 0)
	{
		data.s_counter++;
		write(1, &ch, 1);
		ch = 0;
	}
}
