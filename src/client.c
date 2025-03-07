/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/07 16:04:15 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// client must convert msg in binary and send it to server

// step 1 need server PID
// step 2 need the str to send
// convert in binary then send

int	send_sig(int pid, char *to_send);

/* 
Problematic :
You can only use these two signals: SIGUSR1 and SIGUSR2. 
=> sigusr1 == true // sigusr2 == true -> send 1 or 0
*/
int	send_sig(int pid, char *to_send)
{
	// int			sig;
	// char		*binary;

	// sig = 0;
	// binary = ft_convert_base(to_send, "0123456789", "01");
	// ft_printf("pid : %d\n", pid);
	// ft_printf("binary conversion of to_send (%s) is : %s\n", to_send, binary);
	ft_printf("65 en binaire: %s\n", ft_convert_base("65", "0123456789", "01"));
	(void)to_send;
	(void)pid;
	return (0);
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*to_send;
	int		i;

	if (ac != 3)
		return (0);
	server_pid = ft_atoi(av[1]);
	if (server_pid == 0)
		return (0);
	to_send = av[2];
	i = 0;
	send_sig(server_pid, to_send);
	(void)i;
	// while (to_send[i++])
	// 	send_sig(server_pid, to_send[i]);
	return (0);
}
