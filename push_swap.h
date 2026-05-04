/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:54:18 by pride-ol          #+#    #+#             */
/*   Updated: 2026/05/04 19:07:59 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_config
{
	int				strategy;
	int				bench_mode;
	double			initial_disorder;
	int				op_count[11];
}					t_config;

typedef struct s_node
{
	int				index;
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

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
	int				*i;
	int				limit;
	t_config		*config;
}					t_data;

// sort function
void				sort_handler(t_list *a, t_list *b, t_config *config);

// flags fnctions
int					parse_single_flag(char *str, t_config *config);
void				print_benchmark_report(t_config *config);
int					parse_flags(int argc, char **argv, t_config *config);

// parsing function
int					fill_list(t_list *a, int argc, char **argv, int start);

// parsing helper functions
int					valid_number(char *str);
int					check_duplicates(t_list *a, int n);
long				ft_atol(char *str);

// general utils functions
void				init_list(t_list *list);
void				index_list(t_list *a);
int					is_sorted(t_list *a);
void				free_list(t_list *s);
void				error_exit(t_list *a, t_list *b);

// algorithm functions
void				sort_3(t_list *a, t_config *config);
void				sort_5(t_list *a, t_list *b, t_config *config);
void				simple_sort(t_list *a, t_list *b, t_config *config);
void				chunk_sort(t_list *a, t_list *b, t_config *config);
void				radix_sort(t_list *a, t_list *b, t_config *config);

// algorithm utils functions
void				r_targ(t_list *list, t_node *target, char name,
						t_config *config);

// swap funtions
void				sa(t_list *a, t_config *config);
void				sb(t_list *b, t_config *config);
void				ss(t_list *a, t_list *b, t_config *config);

// push funtions
void				pa(t_list *a, t_list *b, t_config *config);
void				pb(t_list *a, t_list *b, t_config *config);

// rotate functions
void				ra(t_list *a, t_config *config);
void				rb(t_list *b, t_config *config);
void				rr(t_list *a, t_list *b, t_config *config);

// reverse rotate functions
void				rra(t_list *a, t_config *config);
void				rrb(t_list *b, t_config *config);
void				rrr(t_list *a, t_list *b, t_config *config);

#endif