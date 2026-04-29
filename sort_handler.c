/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:02:25 by pride-ol          #+#    #+#             */
/*   Updated: 2026/04/29 18:49:16 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
