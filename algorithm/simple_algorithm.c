/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:24:11 by romdo-na          #+#    #+#             */
/*   Updated: 2026/07/02 21:13:46 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// • Insertion sort adaptation

void	rotate_to_position(t_stack **stack_a, int position, t_bench *bench)
{
	int	size;

	size = stack_size(*stack_a);
	if (position <= size / 2)
	{
		while (position--)
			ra(stack_a, bench);
	}
	else
	{
		position = size - position;
		while (position--)
			rra(stack_a, bench);
	}
}

int	find_insert_position(t_stack *stack_a, int rank_b)
{
	t_stack	*current_a;
	int		position;

	current_a = stack_a;
	position = 0;
	while (current_a->next)
	{
		if (current_a->rank > current_a->next->rank)
		{
			if (rank_b > current_a->rank || rank_b < current_a->next->rank)
				return (position + 1);
		}
		else if (current_a->rank < rank_b && rank_b < current_a->next->rank)
			return (position + 1);
		current_a = current_a->next;
		position++;
	}
	return (0);
}

void	insertion(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	position;
	int	size_a;

	size_a = stack_size(*stack_a);
	while (size_a > 3)
	{
		pb(stack_a, stack_b, bench);
		size_a--;
	}
	sort_three(stack_a, bench);
	while (*stack_b)
	{
		position = find_insert_position(*stack_a, (*stack_b)->rank);
		rotate_to_position(stack_a, position, bench);
		pa(stack_a, stack_b, bench);
	}
	while ((*stack_a)->rank != 1)
		ra(stack_a, bench);
}
