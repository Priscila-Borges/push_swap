/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/28 13:50:07 by bandrade      #+#    #+#                 */
/*   Updated: 2026/05/03 17:13:44 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_out_of_order(t_list *a)
{
	t_node	*current;

	if (!a || !a->top || !a->top->next)
		return (NULL);
	current = a->top;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (current);
		current = current->next;
	}
	if (current->index > a->top->index)
		return (current);
	return (NULL);
}

void	simple_sort(t_list *a, t_list *b)
{
	t_node	*target;

	while (!is_sorted(a))
	{
		target = find_out_of_order(a);
		if (!target)
			break ;
		rotate_to_target(a, target, 'a');
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
