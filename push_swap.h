/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 13:54:18 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/04/22 14:39:07 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

// main function
void				sort_handler(t_stack *a, t_stack *b);

// sorting helper function
double				compute_disorder(t_stack *a);

//parsing function
int					fill_stack(t_stack *a, int argc, char **argv);

//parsing helper functions
int					valid_number(char *str);
int					check_duplicates(t_stack *a, int n);
long				ft_atol(char *str);
void				error_exit(t_stack *a, t_stack *b);

// swap funtions
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

// push funtions
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

// rotate functions
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

// reverse rotate functions
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

#endif