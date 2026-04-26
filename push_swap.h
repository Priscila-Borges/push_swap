/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 13:54:18 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/04/26 16:38:31 by pride-ol      ########   odam.nl         */
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

typedef struct s_list
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_list;

// main function
void				sort_handler(t_list *a, t_list *b);

// sorting helper function
double				compute_disorder(t_list *a);

// parsing function
int					fill_list(t_list *a, int argc, char **argv);

// parsing helper functions
int					valid_number(char *str);
int					check_duplicates(t_list *a, int n);
long				ft_atol(char *str);

// utils functions
void				init_list(t_list *list);
int					is_sorted(t_list *a);
void				free_list(t_list *s);
void				error_exit(t_list *a, t_list *b);

// small disorder sort functions
void				fix_almost_sorted(t_list *a, t_list *b);
t_node				*misplaced_node(t_list *a);
int					distance_bottom(t_list *a, t_node *target);
int					distance_top(t_list *a, t_node *target);
t_node				*find_smallest(t_list *a);
t_node				*find_largest(t_list *a);

// swap funtions
void				sa(t_list *a);
void				sb(t_list *b);
void				ss(t_list *a, t_list *b);

// push funtions
void				pa(t_list *a, t_list *b);
void				pb(t_list *a, t_list *b);

// rotate functions
void				ra(t_list *a);
void				rb(t_list *b);
void				rr(t_list *a, t_list *b);

// reverse rotate functions
void				rra(t_list *a);
void				rrb(t_list *b);
void				rrr(t_list *a, t_list *b);

#endif