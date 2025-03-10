/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:42 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/10 16:42:23 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#define END_SIG '\0'
// https://fr.wikipedia.org/wiki/Manipulation_de_bits

void	handle_sig(int sig);

void	handle_sig(int sig)
{
	static unsigned char	c;
	static int				i;

	c |= (sig == SIGUSR2) << (7 - i);
	i++;
	if (i == 8)
	{
		if (c == END_SIG)
			ft_putchar('\n');
		else
			ft_putchar(c);
		c = 0;
		i = 0;
	}
}

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
