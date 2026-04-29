/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:18:15 by bandrade          #+#    #+#             */
/*   Updated: 2026/04/29 18:22:51 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_top(t_list *a, t_list *b, int *i, int limit)
{
	if (a->top->value <= *i)
	{
		pb(a, b);
		rb(b);
		(*i)++;
	}
	else if (a->top->value <= limit)
	{
		pb(a, b);
		(*i)++;
	}
	else
		ra(a);
}

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

static void	push_chunks(t_list *a, t_list *b, int size)
{
	int	i;
	int	chunk;
	int	limit;

	i = 0;
	chunk = get_chunk_size(size);
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
		rotate_to_node_b(b, max);
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
