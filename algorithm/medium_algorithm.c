/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willpere <willpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:14:19 by romdo-na          #+#    #+#             */
/*   Updated: 2026/07/02 20:02:18 by willpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

 void	return_to_a(t_stack **stack_a, t_stack **stack_b, t_bench *bench, int size)
 {
	int	target;
	int pos;
	int mid;
	t_stack *current_b;
	
	target = size;
	while (*stack_b)
	{
		pos = 0;
		current_b = *stack_b;
		mid = stack_size(*stack_b) / 2;
		while (current_b->rank != target)
		{
			current_b = current_b->next;
			pos++;
		}
		while ((*stack_b)->rank != target)
		{
			if (pos <= mid)
				rb(stack_b, bench);
			else
				rrb(stack_b, bench);
		}
		pa(stack_a, stack_b, bench);
		target--;
	}
} 

 void	bucket(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int size;
	int chunk_size;
	int limit;
	int pushed;
	
	size = stack_size(*stack_a);
	chunk_size = size / 5;
	limit = chunk_size;
	pushed = 0;
	while (*stack_a)
	{
		if (pushed >= limit)
			limit += chunk_size;
		if ((*stack_a)->rank <= limit)
		{
			pb(stack_a, stack_b, bench);
			pushed++;
		}
		else
			ra(stack_a, bench);
	}
	return_to_a(stack_a, stack_b, bench, size);
} 
