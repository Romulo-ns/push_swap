/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:26:19 by romdo-na          #+#    #+#             */
/*   Updated: 2026/07/02 22:40:51 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a, t_bench *bench)
{
	int	last_rank;

	last_rank = find_highest_rank(*stack_a);
	if ((*stack_a)->rank == last_rank)
		ra(stack_a, bench);
	if ((*stack_a)->next->rank == last_rank)
		rra(stack_a, bench);
	if ((*stack_a)->rank > (*stack_a)->next->rank)
		sa(stack_a, bench);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	push_to_b_by_rank(stack_a, stack_b, 1, bench);
	push_to_b_by_rank(stack_a, stack_b, 2, bench);
	sort_three(stack_a, bench);
	pa(stack_a, stack_b, bench);
	pa(stack_a, stack_b, bench);
}

void	take_the_flags(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (strcmp(bench->strategy, STRA_SIMPLE) == 0)
		insertion(stack_a, stack_b, bench);
	else if (strcmp(bench->strategy, STRA_MEDIUM) == 0)
		bucket(stack_a, stack_b, bench);
	else if (strcmp(bench->strategy, STRA_COMPLEX) == 0)
		radix(stack_a, stack_b, bench);
	else
	{
		if (bench->disorder <= 20.00)
			insertion(stack_a, stack_b, bench);
		else if (bench->disorder >= 50.00)
			radix(stack_a, stack_b, bench);
		else
			bucket(stack_a, stack_b, bench);
		return ;
	}
}

void	select_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int		size;

	size = stack_size(*stack_a);
	bench->disorder = get_disorder(*stack_a);
	if (bench->disorder == 0)
		return ;
	if (size <= 5)
	{
		if (size == 2 && (*stack_a)->rank > (*stack_a)->next->rank)
			sa(stack_a, bench);
		else if (size == 3)
			sort_three(stack_a, bench);
		else if (size == 5 || size == 4)
			sort_five(stack_a, stack_b, bench);
		return ;
	}
	else
	{
		take_the_flags(stack_a, stack_b, bench);
	}
}

void	select_strategy(int argc, char **argv, t_bench *bench)
{
	if (strcmp((argv)[1], BENCH_MARK) == 0)
	{
		bench->active += 1;
		bench->print_bench = 1;
		(argv)++;
		(argc)--;
		if (argc < 2)
		{
			putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	check_strategy(argc, argv, bench);
}
