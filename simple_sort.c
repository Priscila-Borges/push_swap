/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:50:07 by bandrade          #+#    #+#             */
/*   Updated: 2026/04/28 17:36:40 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_smallest(t_list *a, t_list *b)
{
	t_node	*min;

	min = find_smallest(a);
	rotate_to_node(a, min);
	pb(a, b);
}

void	simple_sort(t_list *a, t_list *b)
{
	while (a->size > 0)
		push_smallest(a, b);
	while (b->size > 0)
		pa(a, b);
}
