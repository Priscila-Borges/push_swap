/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:01:52 by bandrade          #+#    #+#             */
/*   Updated: 2026/05/06 18:23:07 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			if (!parse_single_flag(argv[i], config))
				error_exit(NULL, NULL);
		}
		else
			break ;
		i++;
	}
	return (i);
}

void	print_disorder(double disorder)
{
	int	whole;
	int	decimal;

	whole = (int)(disorder * 100);
	decimal = (int)(disorder * 10000) % 100;
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}
