/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:51:54 by pride-ol          #+#    #+#             */
/*   Updated: 2026/05/04 16:36:24 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	rra(t_list *a, t_config *config)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	if (config && config->bench_mode)
		config->op_count[1]++;
}

void	rrb(t_list *b, t_config *config)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	if (config && config->bench_mode)
		config->op_count[1]++;
}

void	rrr(t_list *a, t_list *b, t_config *config)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	if (config && config->bench_mode)
		config->op_count[1]++;
}
