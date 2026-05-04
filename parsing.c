/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:19:15 by bandrade          #+#    #+#             */
/*   Updated: 2026/05/04 18:59:33 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_list_bottom(t_list *list, int val)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_exit(list, NULL);
	new_node->value = val;
	new_node->next = NULL;
	if (list->size == 0)
	{
		new_node->prev = NULL;
		list->top = new_node;
		list->bottom = new_node;
	}
	else
	{
		new_node->prev = list->bottom;
		list->bottom->next = new_node;
		list->bottom = new_node;
	}
	list->size++;
}

static int	process_number(t_list *a, char *str)
{
	long	value;

	if (!valid_number(str))
		return (0);
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	if (check_duplicates(a, (int)value))
		return (0);
	add_to_list_bottom(a, (int)value);
	return (1);
}

static void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	process_arg(t_list *a, char *arg)
{
	char	**temp_args;
	int		j;

	temp_args = ft_split(arg, ' ');
	if (!temp_args || !temp_args[0])
		return (free_array(temp_args), 0);
	j = 0;
	while (temp_args[j])
	{
		if (!process_number(a, temp_args[j]))
			return (free_array(temp_args), 0);
		j++;
	}
	free_array(temp_args);
	return (1);
}

int	fill_list(t_list *a, int argc, char **argv, int start)
{
	int	i;

	i = start;
	while (i < argc)
	{
		if (!process_arg(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
