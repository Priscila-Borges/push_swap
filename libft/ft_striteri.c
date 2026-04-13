/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 12:44:12 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/31 11:52:48 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void	test_lowercase(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 'A' && *c <= 'Z')
// 		*c = *c + 32;
// }

// int	main(void)
// {
// 	char	result[] = "BORGES";
// 	ft_striteri(result, test_lowercase);
// 	printf("%s", result);
// 	return (0);
// }