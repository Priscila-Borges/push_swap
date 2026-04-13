/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 13:54:18 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/04/13 15:26:02 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

//main function
void	sort_handler(t_stack *a, t_stack *b);

//swap funtions
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

//push funtions
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

//rotate functions
void	ra(t_stack *a);
void	rb(t_node *b);
void	rr(t_node *a, t_stack *b);

//reverse rotate functions
void	rra(t_stack *a);
void	rrb(t_node *b);
void	rrr(t_stack *a, t_stack *b);
#endif