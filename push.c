/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:51:35 by pride-ol          #+#    #+#             */
/*   Updated: 2026/05/04 16:35:30 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list *src, t_list *dest)
{
	t_node	*node;

	if (!src || src->size == 0)
		return ;
	node = src->top;
	src->top = node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->next = dest->top;
	node->prev = NULL;
	if (dest->top)
		dest->top->prev = node;
	else
		dest->bottom = node;
	dest->top = node;
	dest->size++;
}

void	pb(t_list *a, t_list *b, t_config *config)
{
	push(a, b);
	write(1, "pb\n", 3);
	if (config && config->bench_mode)
		config->op_count[4]++;
}

void	pa(t_list *a, t_list *b, t_config *config)
{
	push(b, a);
	write(1, "pa\n", 3);
	if (config && config->bench_mode)
		config->op_count[3]++;
}
