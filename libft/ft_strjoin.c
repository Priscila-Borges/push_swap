/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/19 16:31:57 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/28 13:58:35 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;	
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_string = malloc(len1 + len2 + 1 * sizeof(char));
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, len1 + 1);
	ft_strlcat(new_string, s2, len1 + len2 + 1);
	return (new_string);
}
