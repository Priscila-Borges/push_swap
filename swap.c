/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 13:52:40 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/04/22 18:48:48 by pride-ol      ########   odam.nl         */
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

void	sa(t_list *a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_list *b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}
