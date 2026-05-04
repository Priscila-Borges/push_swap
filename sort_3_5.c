/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_5.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/28 14:03:55 by bandrade      #+#    #+#                 */
/*   Updated: 2026/05/04 16:20:39 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_smallest(t_list *a)
{
	t_node	*curr;
	t_node	*min;

	curr = a->top;
	min = curr;
	while (curr)
	{
		if (curr->value < min->value)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

static void	push_smallest(t_list *a, t_list *b, t_config *config)
{
	t_node	*min;

	min = find_smallest(a);
	r_targ(a, min, 'a', config);
	pb(a, b, config);
}

void	sort_3(t_list *a, t_config *config)
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
		sa(a, config);
	else if (first > second && second > third)
	{
		sa(a, config);
		rra(a, config);
	}
	else if (first > second && second < third && first > third)
		ra(a, config);
	else if (first < second && second > third && first < third)
	{
		sa(a, config);
		ra(a, config);
	}
	else
		rra(a, config);
}

void	sort_5(t_list *a, t_list *b, t_config *config)
{
	while (a->size > 3)
		push_smallest(a, b, config);
	sort_3(a, config);
	while (b->size > 0)
		pa(a, b, config);
}
