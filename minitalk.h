/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:53:35 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/20 19:22:14 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_data
{
    int		s_counter;
    int		c_counter;
}	t_data;

void	send_char(int pid, char x, t_data *data);
void    ft_init2(t_data *data);
void	sighandler(int signum);
int		ft_atoi(const char *str);
#endif