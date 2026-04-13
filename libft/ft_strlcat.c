/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/16 09:45:14 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/27 13:06:39 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	i;
	size_t	j;

	src_length = ft_strlen(src);
	dst_length = 0;
	while (dst[dst_length] != '\0' && dst_length < size)
		dst_length++;
	if (size <= dst_length)
		return (size + src_length);
	i = 0;
	j = dst_length;
	while (src[i] != '\0' && j < (size - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst_length + src_length);
}
