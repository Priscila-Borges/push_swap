/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrade <bandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:58:30 by pride-ol          #+#    #+#             */
/*   Updated: 2026/05/04 18:42:22 by bandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	parse_single_flag(char *str, t_config *config)
{
	if (ft_strncmp(str, "--simple", 9) == 0)
		config->strategy = 1;
	else if (ft_strncmp(str, "--medium", 9) == 0)
		config->strategy = 2;
	else if (ft_strncmp(str, "--complex", 10) == 0)
		config->strategy = 3;
	else if (ft_strncmp(str, "--adaptive", 11) == 0)
		config->strategy = 0;
	else if (ft_strncmp(str, "--bench", 8) == 0)
		config->bench_mode = 1;
	else
		return (0);
	return (1);
}

static int	get_total_ops(t_config *config)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < 11)
		total += config->op_count[i++];
	return (total);
}

static void	print_bench_header(t_config *config, int total_ops)
{
	ft_putstr_fd("[bench] dis: ", 2);
	ft_putnbr_fd((int)(config->initial_disorder * 100), 2);
	ft_putstr_fd("%\n", 2);
	if (config->strategy == 1)
		ft_putstr_fd("[bench] strategy: Simple Sort / O(n^2)\n", 2);
	else if (config->strategy == 3)
		ft_putstr_fd("[bench] strategy: Radix Sort / O(n log n)\n", 2);
	else
		ft_putstr_fd("[bench] strategy: Adapt / O(n*sqrt(n))\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_bench_ops(t_config *c)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(c->op_count[0], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(c->op_count[1], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(c->op_count[2], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(c->op_count[3], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(c->op_count[4], 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(c->op_count[5], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(c->op_count[6], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(c->op_count[7], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(c->op_count[8], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(c->op_count[9], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(c->op_count[10], 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark_report(t_config *config)
{
	int	total_ops;

	total_ops = get_total_ops(config);
	print_bench_header(config, total_ops);
	print_bench_ops(config);
}
