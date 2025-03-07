/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/07 01:02:57 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// client must convert msg in binary and send it to server

// step 1 need server PID
// step 2 need the str to send
// convert in binary then send
int	main(int ac, char **av)
{
	int		server_pid;
	char	*text;

	if (ac != 3)
		return (0);
	server_pid = ft_atoi(av[1]);
	if (server_pid == 0)
		return (0);
	text = av[2];
	(void)av;
	return (0);
}
