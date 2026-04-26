/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 15:34:55 by bandrade      #+#    #+#                 */
/*   Updated: 2026/04/26 12:14:56 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	a;
	t_list	b;

	if (argc < 2)
		return (0);
	init_list(&a);
	init_list(&b);
	if (!fill_list(&a, argc, argv))
		error_exit(&a, &b);
	sort_handler(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}
