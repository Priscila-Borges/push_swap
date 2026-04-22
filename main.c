/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:34:55 by bandrade          #+#    #+#             */
/*   Updated: 2026/04/22 18:03:57 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// initialize stack a and b to size 0 and top/bottom to NULL
void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (!fill_stack(&a, argc, argv))
		error_exit(&a, &b);
	sort_handler(&a, &b);
	free(&a);
	free(&b);
	return (0);
}
