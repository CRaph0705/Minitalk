/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:09:02 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/16 15:27:50 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#define END_SIG '\0'

void	handle_sig(int sig, siginfo_t *sig_info, void *ptr);
char	*char_to_str(unsigned char c);

char	*char_to_str(unsigned char c)
{
	char	*str;

	str = ft_calloc(2, 1);
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}

void	handle_sig(int sig, siginfo_t *sig_info, void *ptr)
{
	static unsigned char	c;
	static char				*buffer;
	static int				i;

	(void)ptr;
	c |= (sig == SIGUSR2) << (7 - i);
	i++;
	kill(sig_info->si_pid, SIGUSR1);
	if (i == 8)
	{
		if (c == END_SIG)
		{
			ft_printf("%s\n", buffer);
			free(buffer);
			buffer = NULL;
			usleep(100);
			kill(sig_info->si_pid, SIGUSR2);
		}
		else
		{
			buffer = append_and_free(buffer, char_to_str(c));
		}
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("server pid : %d\n", pid);
	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
