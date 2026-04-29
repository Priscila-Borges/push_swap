/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:22:55 by bandrade          #+#    #+#             */
/*   Updated: 2026/04/29 11:34:48 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_to_array(t_list *a)
{
	int		*arr;
	t_node	*curr;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	curr = a->top;
	i = 0;
	while (curr)
	{
		arr[i++] = curr->value;
		curr = curr->next;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	get_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	index_stack(t_list *a)
{
	int		*arr;
	t_node	*curr;

	arr = copy_to_array(a);
	if (!arr)
		return ;
	sort_array(arr, a->size);
	curr = a->top;
	while (curr)
	{
		curr->value = get_index(arr, a->size, curr->value);
		curr = curr->next;
	}
	free(arr);
}
