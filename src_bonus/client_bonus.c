/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:08:56 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/10 19:57:59 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	send_msg(int pid, char *to_send);
void	send_char(int pid, unsigned char c);
void	handle_response(int sig);

void	send_msg(int pid, char *to_send)
{
	int		i;

	i = 0;
	if (!to_send)
		return ;
	while (to_send[i])
	{
		send_char(pid, to_send[i]);
		i++;
	}
	send_char(pid, '\0');
}

void	send_char(int pid, unsigned char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		usleep(100);
		if ((c >> i) & 1)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		i--;
	}
}

void	handle_response(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("msg received\n");
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*to_send;

	signal(SIGUSR1, handle_response);
	signal(SIGUSR2, handle_response);
	if (ac != 3)
	{
		ft_putstr("./client <pid> <msg>");
		exit(1);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		return (0);
	to_send = av[2];
	send_msg(server_pid, to_send);
	return (0);
}
