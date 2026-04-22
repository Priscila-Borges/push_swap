/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 15:34:55 by bandrade      #+#    #+#                 */
/*   Updated: 2026/04/22 18:48:48 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// initialize stack a and b to size 0 and top/bottom to NULL
void	init_list(t_list *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	main(int argc, char **argv)
{
	t_list	a;
	t_list	b;

	if (argc < 2)
		return (0);
	init_list(&a);
	init_list(&b);
	if (!fill_stack(&a, argc, argv))
		error_exit(&a, &b);
	sort_handler(&a, &b);
	free(&a);
	free(&b);
	return (0);
}
