/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:31:36 by pride-ol          #+#    #+#             */
/*   Updated: 2026/05/04 16:36:47 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	distance_top(t_list *list, t_node *target)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = list->top;
	while (curr && curr != target)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

void	r_targ(t_list *list, t_node *target, char name, t_config *config)
{
	int	top_distance;

	if (!list || !target || list->top == target)
		return ;
	top_distance = distance_top(list, target);
	if (top_distance <= list->size / 2)
	{
		while (list->top != target)
		{
			if (name == 'a')
				ra(list, config);
			else
				rb(list, config);
		}
	}
	else
	{
		while (list->top != target)
		{
			if (name == 'a')
				rra(list, config);
			else
				rrb(list, config);
		}
	}
}
