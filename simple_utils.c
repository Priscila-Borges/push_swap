/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:35:45 by bandrade          #+#    #+#             */
/*   Updated: 2026/04/29 18:49:27 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_list *a)
{
	t_node	*curr;
	t_node	*min;

	curr = a->top;
	min = curr;
	while (curr)
	{
		if (curr->value < min->value)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

int	distance_top(t_list *a, t_node *target)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = a->top;
	while (curr && curr != target)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

int	distance_bottom(t_list *a, t_node *target)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = a->bottom;
	while (curr && curr != target)
	{
		curr = curr->prev;
		i++;
	}
	return (i);
}

void	rotate_to_node(t_list *a, t_node *target)
{
	int	top;
	int	bottom;

	while (a->top != target)
	{
		top = distance_top(a, target);
		bottom = distance_bottom(a, target);
		if (top <= bottom)
			ra(a);
		else
			rra(a);
	}
}
