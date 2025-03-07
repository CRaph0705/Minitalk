/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:42 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/07 18:53:10 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//step 1 : get its pid and display it
// handle sig reception / errors
// translate binary in ascii/char??

// https://fr.wikipedia.org/wiki/Manipulation_de_bits
void	handle_sig(int sig);


//int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact); ???
void	handle_sig(int sig)
{
	static int	c;
	int			bit;

	ft_printf("got pinged\n");
	bit = 0;
	c = 0;
	if (sig == SIGUSR1)
		c = c << 1;
	else if (sig == SIGUSR2)
		c = c << 1 | 1;
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}
// pause - wait for signal
// man pause

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("server pid : %d\n", pid);
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
		pause();
	return (0);
}
