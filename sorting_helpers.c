/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_helpers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 12:33:34 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/04/22 18:48:48 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*make_array(t_list *a);
static t_node	*get_node_at_index(t_list *a, int index);

double	compute_disorder(t_list *a)
{
	int	mistakes;
	int	total_pairs;
	int	*array;
	int	i;
	int	j;

	array = make_array(a);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs += 1;
			if (array[i] > array[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}

static int	*make_array(t_list *a)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * a->size);
	if (!array)
		return (0);
	i = 0;
	while (i < a->size)
	{
		array[i] = get_node_at_index(a, i)->value;
		i++;
	}
	return (array);
}

static t_node	*get_node_at_index(t_list *a, int index)
{
	t_node	*current;
	int		i;

	current = a->top;
	i = 0;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}
