/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/07 18:30:36 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// client must convert msg in binary and send it to server

// step 1 need server PID
// step 2 need the str to send
// convert in binary then send

void	send_sig(int pid, unsigned char *to_send);

/* 
Problematic :
You can only use these two signals: SIGUSR1 and SIGUSR2. 
=> sigusr1 == true // sigusr2 == true -> send 1 or 0
=> usleep() pour ajouter un délai entre chaque envoi ?
*/

void	send_sig(int pid, unsigned char *to_send)
{
	char	*sig;
	int		i;
	int		bit;

	i = 0;
	while (to_send[i] || i == 0)
	{
		sig = ft_convert_base(ft_itoa(to_send[i]), "0123456789", "01");
		if (!sig)
			return ;
		bit = 0;
		while (sig[bit])
		{
			if (sig[bit] == '0')
				kill(pid, SIGUSR1);
			else if (sig[bit] == '1')
				kill(pid, SIGUSR2);
			bit++;
		}
		usleep(30);
		free(sig);
		i++;
	}
}

int	main(int ac, char **av)
{
	int				server_pid;
	unsigned char	*to_send;

	if (ac != 3)
		return (0);
	server_pid = ft_atoi(av[1]);
	if (server_pid == 0)
		return (0);
	to_send = (unsigned char *)av[2];
	send_sig(server_pid, to_send);
	return (0);
}
