/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:05:34 by pride-ol          #+#    #+#             */
/*   Updated: 2026/04/22 18:04:20 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *a, int n)
{
	t_node	*current;

	if (!a || !a->top)
		return (0);
	current = a->top;
	while (current)
	{
		if (current->value == n)
			return (1);
		current = current->next;
	}
	return (0);
}

long	ft_atol(char *str)
{
	long	number;
	int		sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

static void	free_stack(t_stack *s)
{
	t_node	*current;
	t_node	*next;

	if (!s || !s->top)
		return ;
	current = s->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

void	error_exit(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
