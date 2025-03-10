/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:09:02 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/10 20:07:41 by rcochran         ###   ########.fr       */
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
	if (i == 8)
	{
		if (c == END_SIG)
		{
			ft_printf("%s\n", buffer);
			free(buffer);
			buffer = NULL;
			kill(sig_info->si_pid, SIGUSR1);
		}
		else
		{
			buffer = append_and_free(buffer, char_to_str(c));
		}
		c = 0;
		i = 0;
	}
}

/*
 * Signal vector "template" used in sigaction call.
 */
// struct  sigaction {
// 	union __sigaction_u __sigaction_u;  /* signal handler */
// 	sigset_t sa_mask;               /* signal mask to apply */
// 	int     sa_flags;               /* see signal options below */
// };
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
