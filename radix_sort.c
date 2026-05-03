/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/29 14:28:51 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/05/03 17:18:49 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_bits(int max_value)
{
	int	bits;

	bits = 0;
	while ((max_value >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_list *a, t_list *b)
{
	int	bit;
	int	bit_max;
	int	list_size;	

	bit_max = find_bits(a->size -1);
	bit = 0;
	while (bit < bit_max)
	{
		list_size = a->size;
		while (list_size--)
		{
			if (((a->top->index >> bit) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
