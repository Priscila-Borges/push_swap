/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/29 17:18:15 by bandrade      #+#    #+#                 */
/*   Updated: 2026/05/03 17:12:04 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_top(t_list *a, t_list *b, int *i, int limit)
{
	if (a->top->index <= *i)
	{
		pb(a, b);
		rb(b);
		(*i)++;
	}
	else if (a->top->index <= limit)
	{
		pb(a, b);
		(*i)++;
	}
	else
		ra(a);
}

static t_node	*find_largest(t_list *a)
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

static void	push_chunks(t_list *a, t_list *b, int size)
{
	int	i;
	int	chunk;
	int	limit;

	i = 0;
	if (size <= 100)
		chunk = 15;
	else
		chunk = 30;
	limit = chunk;
	while (a->size > 0)
	{
		process_top(a, b, &i, limit);
		if (i >= limit)
			limit += chunk;
	}
}

static void	push_back(t_list *a, t_list *b)
{
	t_node	*max;

	while (b->size > 0)
	{
		max = find_largest(b);
		rotate_to_target(b, max, 'b');
		pa(a, b);
	}
}

void	chunk_sort(t_list *a, t_list *b)
{
	int	size;

	size = a->size;
	push_chunks(a, b, size);
	push_back(a, b);
}
