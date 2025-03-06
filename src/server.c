/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:42 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/06 20:21:16 by rcochran         ###   ########.fr       */
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
	return (0);
}
