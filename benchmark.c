/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 11:26:14 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/27 15:26:57 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_double_fd(double dis);
void    print_benchmark_moves(t_bench *bench);

void	bench_initiate(t_bench *bench)
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

void	print_benchmark(t_bench *bench)
{
	putstr_fd("\n[bench] disorder: ", 2);
	print_double_fd(bench->disorder);
	putstr_fd("\n[bench] strategy: ", 2);
	putstr_fd(bench->strategy, 2);
	putstr_fd("\n[bench] total_ops: ", 2);
	putnbr_fd(bench->total_ops, 2);
	print_benchmark_moves(bench);
}

void	print_benchmark_moves(t_bench *bench)
{
	putstr_fd("\n[bench] sa: ", 2);
	putnbr_fd(bench->sa, 2);
	putstr_fd("\tsb: ", 2);
	putnbr_fd(bench->sb, 2);
	putstr_fd("\tss: ", 2);
	putnbr_fd(bench->ss, 2);
	putstr_fd("\tpa: ", 2);
	putnbr_fd(bench->pa, 2);
	putstr_fd("\tpb: ", 2);
	putnbr_fd(bench->pb, 2);
	putstr_fd("\n[bench] ra: ", 2);
	putnbr_fd(bench->ra, 2);
	putstr_fd("\trb: ", 2);
	putnbr_fd(bench->rb, 2);
	putstr_fd("\trr: ", 2);
	putnbr_fd(bench->rr, 2);
	putstr_fd("\trra: ", 2);
	putnbr_fd(bench->rra, 2);
	putstr_fd("\trrb: ", 2);
	putnbr_fd(bench->rrb, 2);
	putstr_fd("\trrr: ", 2);
	putnbr_fd(bench->rrr, 2);
	putstr_fd("\n", 2);
}

void	print_double_fd(double disorder)
{
	int	inteiro;

	inteiro = disorder;
	disorder -= inteiro;
	disorder *= 100;
	putnbr_fd(inteiro, 2);
	putstr_fd(".", 2);
	if (disorder < 10)
		putnbr_fd(0, 2);
	putnbr_fd(disorder, 2);
	putstr_fd("%", 2);
}
