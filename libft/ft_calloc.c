/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 17:44:44 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/18 12:53:13 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	memsize;
	void	*pointer;

	if (size != 0 && nmemb > INT_MAX / size)
		return (NULL);
	memsize = nmemb * size;
	pointer = malloc(memsize);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, memsize);
	return (pointer);
}
