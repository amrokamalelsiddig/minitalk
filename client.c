/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:25:43 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/09/25 14:37:16 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int		n;
	int		pid;

	(void)argc;
	pid = ft_atoi(argv[1]);
	n = 0;
	if (!(pid) || !(argv[2]) || pid < 100)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	while (argv[2][n])
	{
		send_char(pid, argv[2][n]);
		n++;
	}
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

static void	ft_init(int *i, long long int *s, unsigned long long int *n)
{
	*i = 0;
	*s = 1;
	*n = 0;
}

int	ft_atoi(const char *str)
{
	int							i;
	long long int				s;
	unsigned long long int		n;

	ft_init(&i, &s, &n);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			s = -s;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	if (n > 9223372036854775807)
	{
		if (s == 1)
			return (-1);
		return (0);
	}
	return ((int)(s * n));
}
