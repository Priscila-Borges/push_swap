/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:07:08 by bandrade          #+#    #+#             */
/*   Updated: 2026/04/29 18:31:09 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_largest(t_list *a)
{
	t_node	*curr;
	t_node	*max;

	curr = a->top;
	max = curr;
	while (curr)
	{
		if (curr->value > max->value)
			max = curr;
		curr = curr->next;
	}
	return (max);
}

void	rotate_to_node_b(t_list *b, t_node *target)
{
	int	top;
	int	bottom;

	while (b->top != target)
	{
		top = distance_top(b, target);
		bottom = distance_bottom(b, target);
		if (top <= bottom)
			rb(b);
		else
			rrb(b);
	}
}
