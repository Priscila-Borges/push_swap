/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/23 11:21:21 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/24 11:14:57 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	num_len(long int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*string;
	int				length;
	long int		number;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = num_len(n);
	string = ft_calloc(length + 1, sizeof(char));
	if (!string)
		return (NULL);
	number = n;
	if (number == 0)
		string[0] = '0';
	if (n < 0)
	{
		string[0] = '-';
		number = -n;
	}
	while (number > 0)
	{
		length--;
		string[length] = (number % 10) + '0';
		number = number / 10;
	}
	return (string);
}
