/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:52:12 by pride-ol          #+#    #+#             */
/*   Updated: 2026/05/04 16:36:19 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	first->next = NULL;
	first->prev = stack->bottom;
	stack->bottom->next = first;
	stack->bottom = first;
}

void	ra(t_list *a, t_config *config)
{
	rotate(a);
	write(1, "ra\n", 3);
	if (config && config->bench_mode)
		config->op_count[5]++;
}

void	rb(t_list *b, t_config *config)
{
	rotate(b);
	write(1, "rb\n", 3);
	if (config && config->bench_mode)
		config->op_count[6]++;
}

void	rr(t_list *a, t_list *b, t_config *config)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	if (config && config->bench_mode)
		config->op_count[7]++;
}
