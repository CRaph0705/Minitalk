/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/10 16:28:32 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// client must convert msg in binary and send it to server

// step 1 need server PID
// step 2 need the str to send
// convert in binary then send
/* 
Problematic :
You can only use these two signals: SIGUSR1 and SIGUSR2. 
=> sigusr1 == true // sigusr2 == true -> send 1 or 0
=> usleep() pour ajouter un délai entre chaque envoi ?
*/
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

int	main(int ac, char **av)
{
	int		server_pid;
	char	*to_send;

	if (ac != 3)
	{
		ft_printf("./client <pid> <msg>");
		exit(1);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		return (0);
	to_send = av[2];
	send_msg(server_pid, to_send);
	return (0);
}
