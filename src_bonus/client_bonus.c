/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:08:56 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/10 15:13:07 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, unsigned char *to_send);
void	send_char(int pid, unsigned char c);
void	send_null(int pid);
void	handle_response(int sig);

void	send_msg(int pid, unsigned char *to_send)
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
	send_null(pid);
}

void	send_char(int pid, unsigned char c)
{
	char	*binary;
	int		index;

	binary = ft_convert_base(ft_itoa(c), "0123456789", "01");
	if (!binary)
		return (send_null(pid));
	index = 0;
	while (binary[index])
	{
		send_char(pid, c);
		index++;
		usleep(100);
	}
	free(binary);
	if (binary[index] == '0')
		kill(pid, SIGUSR1);
	else if (binary[index] == '1')
		kill(pid, SIGUSR2);
}

void	send_null(int pid)
{
	int	i;

	i = 8;
	while (i != 0)
	{
		kill(pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

void	handle_response(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("'1' received");
	else if (sig == SIGUSR2)
		ft_printf("'0' received");
	else
		return ;
}

int	main(int ac, char **av)
{
	int				server_pid;
	unsigned char	*to_send;

	if (ac != 3)
		exit(1);
	signal(SIGUSR1, handle_response);
	signal(SIGUSR2, handle_response);
	server_pid = ft_atoi(av[1]);
	if (server_pid == 0)
		return (0);
	to_send = (unsigned char *)av[2];
	send_msg(server_pid, to_send);
	return (0);
}
