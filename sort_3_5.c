/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:03:55 by bandrade          #+#    #+#             */
/*   Updated: 2026/04/28 17:51:06 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sort_3(t_list *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else
		rra(a);
}

void	push_smallest_to_b(t_list *a, t_list *b)
{
	t_node	*min;

	min = find_smallest(a);
	rotate_to_node(a, min);
	pb(a, b);
}

void	sort_5(t_list *a, t_list *b)
{
	while (a->size > 3)
		push_smallest_to_b(a, b);
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}
