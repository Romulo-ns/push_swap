/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 21:49:19 by romdo-na          #+#    #+#             */
/*   Updated: 2026/07/02 22:40:03 by romdo-na         ###   ########.fr       */
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

void	check_strategy(int argc, char **argv, t_bench *bench)
{
	if (bench && (argv[1][0] == '-' && argv[1][1] == '-'))
	{
		bench->active += 1;
		if (strcmp((argv)[1], STRA_SIMPLE) == 0)
			bench->strategy = STRA_SIMPLE;
		else if (strcmp((argv)[1], STRA_MEDIUM) == 0)
			bench->strategy = STRA_MEDIUM;
		else if (strcmp((argv)[1], STRA_COMPLEX) == 0)
			bench->strategy = STRA_COMPLEX;
		else if (strcmp((argv)[1], "") != 0
			&& strcmp((argv)[1], STRA_ADAPTIVE) != 0)
			bench->strategy = "Invalid";
		else
			bench->strategy = STRA_ADAPTIVE;
		if (strcmp(bench->strategy, "Invalid") != 0)
		{
			(argv)++;
			(argc)--;
		}
	}
}
