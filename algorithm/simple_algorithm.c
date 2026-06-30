/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:24:11 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/30 17:48:32 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// • Insertion sort adaptation

void rotate_to_position(t_stack **stack_a, int position, t_bench *bench)
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

int	find_insert_position(t_stack *stack_a, int rank)
{
	t_stack	*current;
	int		position;

	current = stack_a;
	position = 0;
	while (current->next)
	{
		if (current->rank > current->next->rank)
		{
			if (rank > current->rank || rank < current->next->rank)
				return (position + 1);
		}
		else if (current->rank < rank && rank < current->next->rank)
			return (position + 1);
		current = current->next;
		position++;
	}
	return (0);
}

void insertion(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int position;
	int	size_a = stack_size(*stack_a);

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
