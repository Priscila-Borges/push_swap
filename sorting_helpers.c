/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:33:34 by pride-ol          #+#    #+#             */
/*   Updated: 2026/04/28 17:27:34 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*make_array(t_list *a);
static t_node	*get_node_at_index(t_list *a, int index);
static int		count_mistakes(int *array, int size);
static int		count_pairs(int size);

double	compute_disorder(t_list *a)
{
	int	*array;
	int	mistakes;
	int	total;

	array = make_array(a);
	if (!array)
		return (0);
	mistakes = count_mistakes(array, a->size);
	total = count_pairs(a->size);
	free(array);
	return ((double)mistakes / total);
}

static int	count_mistakes(int *array, int size)
{
	int	i;
	int	j;
	int	mistakes;

	i = 0;
	mistakes = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes);
}

static int	count_pairs(int size)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < size - 1)
	{
		total += size - i - 1;
		i++;
	}
	return (total);
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
