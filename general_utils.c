/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 12:11:50 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/05/03 17:23:41 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(t_list *list)
{
	list->top = NULL;
	list->bottom = NULL;
	list->size = 0;
}

void	index_list(t_list *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	is_sorted(t_list *a)
{
	t_node	*curr;

	if (!a || a->size < 2)
		return (1);
	curr = a->top;
	while (curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	free_list(t_list *s)
{
	t_node	*current;
	t_node	*next;

	if (!s || !s->top)
		return ;
	current = s->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

void	error_exit(t_list *a, t_list *b)
{
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	write(2, "Error\n", 6);
	exit(1);
}
