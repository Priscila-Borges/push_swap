/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_disorder.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 12:41:30 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/04/26 16:43:27 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_local_inversion(t_list *a)
{
	if (a->size < 2)
		return (0);
	if (a->top->value > a->top->next->value)
		return (1);
	return (0);
}

static t_node *find_spot(t_list *a, int value)
{
    t_node *curr = a->top;

    if (value < find_smallest(a)->value)
        return (NULL);
	 if (value > find_largest(a)->value)
        return (find_largest(a));
    while (curr && curr->next)
    {
        if (value > curr->value && value < curr->next->value)
            return (curr);
        curr = curr->next;
    }
    return (NULL);
}

// static void small_insertion(t_list *a, t_list *b)
// {
//     int    dist_top;
//     int    dist_bottom;
//     t_node *spot;

//     pb(a, b);
//     spot = find_spot(a, b->top->value);
//     if (spot == NULL)
//     {
//         pa(a, b);
//         return ;
//     }
//     while (a->top != spot)
//     {
//         dist_top = distance_top(a, spot);
//         dist_bottom = distance_bottom(a, spot);
//         if (dist_top <= dist_bottom)
//             ra(a);
//         else
//             rra(a);
//     }
//     pa(a, b);
// }

static void small_insertion(t_list *a, t_list *b, t_node *target)
{
    int    dist_top;
    int    dist_bottom;
    t_node *spot;
    
    while (a->top != target)
    {
        dist_top = distance_top(a, target);
        dist_bottom = distance_bottom(a, target);
        if (dist_top <= dist_bottom)
            ra(a);
        else
            rra(a);
    }
    pb(a, b);
    spot = find_spot(a, b->top->value);
    if (spot == NULL)
    {
        pa(a, b);
        return ;
    }
    while (a->top != spot)
    {
        dist_top = distance_top(a, spot);
        dist_bottom = distance_bottom(a, spot);
        if (dist_top <= dist_bottom)
            ra(a);
        else
            rra(a);
    }
    pa(a, b);
}

static void	small_rotation(t_list *a)
{
	t_node	*min_node;
	int		dist_top;
	int		dist_bottom;

	min_node = find_smallest(a);
	dist_top = distance_top(a, min_node);
	dist_bottom = distance_bottom(a, min_node);
	if (dist_top <= dist_bottom)
	{
		while (a->top != min_node)
			ra(a);
	}
	else
	{
		while (a->top != min_node)
			rra(a);
	}
}

void	fix_almost_sorted(t_list *a, t_list *b)
{
	t_node	*misplaced;
	
	if (has_local_inversion(a))
	{
		sa(a);
		return ;
	}
	misplaced = misplaced_node(a);
	if (misplaced)
	{
		small_insertion(a, b, misplaced);
		return ;
	}
	small_rotation(a);
}
