/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/13 17:08:26 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/27 12:53:33 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_new;
	unsigned char	*src_new;		

	if (!dest && !src)
		return (dest);
	dest_new = (unsigned char *) dest;
	src_new = (unsigned char *) src;
	if (dest_new < src_new)
	{
		while (n--)
			*dest_new++ = *src_new++;
	}
	else
	{
		while (n > 0)
		{
			n--;
			dest_new[n] = src_new[n];
		}
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {	
// 	char	name[15] = "PriscilaBorges";
// 	printf("original: %s | mine: %s \n\n", 
// (char *)memmove((name + 5), name, 6), 
// (char*)ft_memmove((name + 5), name, 6));
// 	return (0);
// }