/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/19 19:40:01 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/29 13:37:41 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **array, int index)
{
	while (index >= 0)
	{
		free(array[index]);
		index--;
	}
	free(array);
	return (NULL);
}

static char	**make_array(char const *s, char c)
{
	char	**array;
	int		i;
	int		word_counter;	

	i = 0;
	word_counter = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word_counter++;
		i++;
	}
	array = ft_calloc((word_counter + 1), sizeof(char *));
	if (!array)
		return (NULL);
	return (array);
}

static char	**add_words(char **array, char const *s, char c)
{
	size_t	i;
	size_t	array_index;
	size_t	start;

	i = 0;
	array_index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			array[array_index] = ft_substr(s, start, i - start);
			if (!array[array_index])
				return (free_all(array, array_index));
			array_index++;
		}
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = make_array(s, c);
	if (!array)
		return (NULL);
	return (add_words(array, s, c));
}

// #include <stdio.h>
// int main(void)
// {
// 	char	**array = ft_split("**Priscila*Borges**42*", '*');
// 	int		i = 0;

// 	while (array && array[i])
// 	{
// 		printf("word[%d]: %s\n", i, array[i]);
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return(0);
// }