/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:42 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/07 00:29:17 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//server must display the msg sent by the client

//step 1 : get its pid and display it
// handle sig reception / errors
// translate binary in ascii/char
int	main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	ft_printf("server pid : %i", pid);
	(void)ac;
	(void)av;
	return (0);
}
