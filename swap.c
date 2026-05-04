/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:52:40 by pride-ol          #+#    #+#             */
/*   Updated: 2026/05/04 16:36:01 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_list *x)
{
	int	temp;

	if (!x || x->size < 2)
		return (0);
	temp = x->top->value;
	x->top->value = x->top->next->value;
	x->top->next->value = temp;
	return (1);
}

void	sa(t_list *a, t_config *config)
{
	if (swap(a))
	{
		write(1, "sa\n", 3);
		if (config && config->bench_mode)
			config->op_count[0]++;
	}
}

void	sb(t_list *b, t_config *config)
{
	if (swap(b))
	{
		write(1, "sb\n", 3);
		if (config && config->bench_mode)
			config->op_count[1]++;
	}
}

void	ss(t_list *a, t_list *b, t_config *config)
{
	if (a->size >= 2 && b->size >= 2)
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
		if (config && config->bench_mode)
			config->op_count[2]++;
	}
}
