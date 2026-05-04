/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:02:25 by pride-ol          #+#    #+#             */
/*   Updated: 2026/05/04 16:36:07 by bandrade         ###   ########.fr       */
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

static void	strategies(t_list *a, t_list *b, t_config *config)
{
	if (config->strategy == 1)
		simple_sort(a, b, config);
	else if (config->strategy == 2)
		chunk_sort(a, b, config);
	else if (config->strategy == 3)
		radix_sort(a, b, config);
}

void	sort_handler(t_list *a, t_list *b, t_config *config)
{
	config->initial_disorder = compute_disorder(a);
	if (is_sorted(a))
		return ;
	strategies(a, b, config);
	if (a->size == 2)
		sa(a, config);
	else if (a->size == 3)
		sort_3(a, config);
	else if (a->size <= 5)
		sort_5(a, b, config);
	else
	{
		if (config->initial_disorder < 0.2)
			simple_sort(a, b, config);
		else if (config->initial_disorder < 0.5)
			chunk_sort(a, b, config);
		else
			radix_sort(a, b, config);
	}
}
