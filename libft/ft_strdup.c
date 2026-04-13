/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/18 13:10:33 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/19 16:25:52 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		s_len;	
	char		*pointer;

	s_len = ft_strlen(s);
	pointer = malloc(s_len + 1 * sizeof(char));
	if (!pointer)
		return (NULL);
	ft_strlcpy(pointer, s, s_len + 1);
	return (pointer);
}
