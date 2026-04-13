/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 11:28:13 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/24 12:37:55 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		strlen;
	int		i;

	if (!s || !(*f))
		return (NULL);
	strlen = ft_strlen(s);
	new_str = ft_calloc(strlen + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}

// #include <stdio.h>

// char	test_uppercase(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'a' && c <= 'z')
// 		return (c = c - 32);
// 	return (c);
// }

// int	main(void)
// {
// 	char	name[] = "priscila";
// 	char	*result = ft_strmapi(name, test_uppercase);
// 	printf("%s", result);
// 	free(result);
// 	return (0);
// }