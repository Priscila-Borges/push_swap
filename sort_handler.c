/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:02:25 by pride-ol          #+#    #+#             */
/*   Updated: 2026/04/22 17:58:10 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_handler(t_stack *a, t_stack *b)
// {
// 	double	disorder;

// 	(void)a;
// 	(void)b;
// 	disorder = compute_disorder(a);
// 	if (disorder < 0.2) // Low disorder O(n) time
// 	{
// 	}
// 	else if (disorder >= 0.2 && disorder < 0.5) // Medium disorder O(nn) time
// 	{
// 	}
// 	else if (disorder > 0.5) // High disorder O(n log n) time
// 	{
// 	}
// }
{
	(void)b;
	if (a->size > 1)
		sa(a);
}
