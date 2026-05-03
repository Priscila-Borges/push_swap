/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_handler.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 13:02:25 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/05/03 17:18:06 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	compute_disorder(t_list *a)
{
	t_node	*current;
	t_node	*runner;
	int		mistakes;
	int		total_pairs;

	if (!a || a->size < 2)
		return (0.0);
	mistakes = 0;
	current = a->top;
	while (current && current->next)
	{
		runner = current->next;
		while (runner)
		{
			if (current->index > runner->index)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
	}
	total_pairs = a->size * (a->size - 1) / 2;
	return ((double)mistakes / total_pairs);
}

void	sort_handler(t_list *a, t_list *b)
{
	double	d;

	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
	{
		d = compute_disorder(a);
		if (d < 0.2)
			simple_sort(a, b);
		else if (d < 0.5)
			chunk_sort(a, b);
		else
			radix_sort(a, b);
	}
}
