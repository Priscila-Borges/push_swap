/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_disorder_helpers.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 14:19:18 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/04/26 16:44:02 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_list *a)
{
	t_node	*current;
	t_node	*min_node;	

	if (a->size == 0)
		return (NULL);
	current = a->top;
	min_node = current;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*find_largest(t_list *a)
{
	t_node	*current;
	t_node	*max_node;	

	if (a->size == 0)
		return (NULL);
	current = a->top;
	max_node = current;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

int	distance_top(t_list *a, t_node *target)
{
	int		distance;
	t_node	*current;

	distance = 0;
	current = a->top;
	while (current && current != target)
	{
		current = current->next;
		distance++;
	}
	return (distance);
}

int	distance_bottom(t_list *a, t_node *target)
{
	int		distance;
	t_node	*current;

	distance = 0;
	current = a->bottom;
	while (current && current != target)
	{
		current = current->prev;
		distance++;
	}
	return (distance);
}

t_node	*misplaced_node(t_list *a)
{
	t_node	*current;

	if (a->size < 3)
		return (NULL);
	current = a->top->next;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (current);
		current = current->next;
	}
	return (NULL);
}
