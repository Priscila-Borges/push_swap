/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_handler.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 13:02:25 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/04/26 16:34:07 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_handler(t_list *a, t_list *b)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		while (!is_sorted(a))
			fix_almost_sorted(a, b);
	else if (disorder < 0.5)
	{
		while (!is_sorted(a))
			fix_almost_sorted(a, b);
		write(1, "disorder < 0.5", 15);
	}
	else if (disorder > 0.5)
	{
	}
}
