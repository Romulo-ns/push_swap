/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 21:49:19 by romdo-na          #+#    #+#             */
/*   Updated: 2026/07/02 21:56:22 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest_rank(t_stack *stack_a)
{
	int	highest_rank;

	highest_rank = stack_a->rank;
	while (stack_a)
	{
		if (stack_a->rank > highest_rank)
			highest_rank = stack_a->rank;
		stack_a = stack_a->next;
	}
	return (highest_rank);
}

void	push_to_b_by_rank(t_stack **stack_a, t_stack **stack_b,
			int stack_rank, t_bench *bench)
{
	t_stack	*top_stack;
	int		pos;
	int		size;

	top_stack = *stack_a;
	pos = 0;
	size = stack_size(*stack_a);
	while (top_stack->rank != stack_rank)
	{
		top_stack = top_stack->next;
		pos++;
	}
	while ((*stack_a)->rank != stack_rank)
	{
		if (pos <= (size / 2))
			ra(stack_a, bench);
		else
			rra(stack_a, bench);
	}
	pb(stack_a, stack_b, bench);
}

void	check_benchmark(int argc, char **argv, t_bench *bench)
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
}
