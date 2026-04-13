/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/16 16:42:07 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/27 12:52:43 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_new;
	unsigned char	*s2_new;
	size_t			i;

	s1_new = (unsigned char *)s1;
	s2_new = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_new[i] != s2_new[i])
			return (s1_new[i] - s2_new[i]);
		i++;
	}
	return (0);
}
