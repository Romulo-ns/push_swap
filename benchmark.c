/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 11:26:14 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/27 12:29:01 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bench_initiate(t_bench *bench)
{
    if (!bench)
		return ;
	bench->active = 0;
	bench->strategy = STRA_ADAPTIVE;
    bench->total_ops = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
}

void	ft_print_benchmark(t_bench *bench)
{
	ft_putstr_fd("\n[bench] disorder: ", 2);
	ft_print_double_fd(bench->disorder);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd(bench->strategy, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_print_benchmark_moves(bench);
}

void	ft_print_benchmark_moves(t_bench *bench)
{
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("\tsb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("\tss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("\tpa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("\tpb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("\trb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("\trr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("\trra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("\trrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("\trrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_double_fd(double disorder)
{
	int	inteiro;

	inteiro = disorder;
	disorder -= inteiro;
	disorder *= 100;
	ft_putnbr_fd(inteiro, 2);
	ft_putstr_fd(".", 2);
	if (disorder < 10)
		ft_putnbr_fd(0, 2);
	ft_putnbr_fd(disorder, 2);
	ft_putstr_fd("%", 2);
}
