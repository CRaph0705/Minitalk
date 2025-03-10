/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:09:02 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/10 18:17:20 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#define END_SIG '\0'

void	handle_sig(int sig);

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

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
		memset(str, 0, size + 1);
	return (str);
}

void	handle_sig(int sig)
{
	static unsigned char	c;
	static char				*buffer;
	static int				i;

	c |= (sig == SIGUSR2) << (7 - i);
	i++;
	if (i == 8)
	{
		if (c == END_SIG)
		{
			ft_printf("%s\n", buffer);
			free(buffer);
			buffer = NULL;
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
	int	pid;

	pid = getpid();
	ft_printf("server pid : %d\n", pid);
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
		pause();
	return (0);
}
