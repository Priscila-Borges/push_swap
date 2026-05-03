/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/03 15:31:36 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/05/03 17:25:07 by pride-ol      ########   odam.nl         */
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

void	rotate_to_target(t_list *list, t_node *target, char name)
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
				ra(list);
			else
				rb(list);
		}
	}
	else
	{
		while (list->top != target)
		{
			if (name == 'a')
				rra(list);
			else
				rrb(list);
		}
	}
}
