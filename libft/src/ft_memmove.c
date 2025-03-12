/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:23:37 by rcochran          #+#    #+#             */
/*   Updated: 2024/11/20 18:08:30 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((!src && !dest) || !n)
		return ((void *)dest);
	i = n;
	if (src < dest)
	{
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
		return (dest);
	}
	while (i--)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	return (dest - n);
}

/* int	main(int ac, char **av)
{
	(void) ac;
	char	*dest = av[1];
	char	*src = av[1] + 2;
	size_t	n =(size_t)atoi(av[2]);
	// printf("test 1 memmove() : %s\n", (char *)memmove(dest, src, n));
	printf("test 2 : ft_memmove() : %s\n", (char *)ft_memmove(dest, src, n));

} */
