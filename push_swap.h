/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 13:54:18 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/04/22 18:47:20 by pride-ol      ########   odam.nl         */
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
int					fill_stack(t_list *a, int argc, char **argv);

// parsing helper functions
int					valid_number(char *str);
int					check_duplicates(t_list *a, int n);
long				ft_atol(char *str);
void				error_exit(t_list *a, t_list *b);
// void				free_stack(t_list *s);

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