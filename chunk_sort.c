/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:18:15 by bandrade          #+#    #+#             */
/*   Updated: 2026/05/04 16:32:34 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_top(t_data *d)
{
	if (d->a->top->index <= *d->i)
	{
		pb(d->a, d->b, d->config);
		rb(d->b, d->config);
		(*d->i)++;
	}
	else if (d->a->top->index <= d->limit)
	{
		pb(d->a, d->b, d->config);
		(*d->i)++;
	}
	else
		ra(d->a, d->config);
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

static void	push_chunks(t_list *a, t_list *b, int size, t_config *config)
{
	int		i;
	int		chunk;
	t_data	d;

	i = 0;
	if (size <= 100)
		chunk = 15;
	else
		chunk = 30;
	d.a = a;
	d.b = b;
	d.config = config;
	d.i = &i;
	d.limit = chunk;
	while (a->size > 0)
	{
		process_top(&d);
		if (i >= d.limit)
			d.limit += chunk;
	}
}

static void	push_back(t_list *a, t_list *b, t_config *config)
{
	t_node	*max;

	while (b->size > 0)
	{
		max = find_largest(b);
		r_targ(b, max, 'b', config);
		pa(a, b, config);
	}
}

void	chunk_sort(t_list *a, t_list *b, t_config *config)
{
	int	size;

	size = a->size;
	push_chunks(a, b, size, config);
	push_back(a, b, config);
}
