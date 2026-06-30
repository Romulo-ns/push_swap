/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willpere <willpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:14:15 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/30 21:21:21 by willpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		radix(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	size;
	int	max_bit;
	int	max_rank;
	int	i;
	int	j;

	size = stack_size(*stack_a);
	max_rank = size;
	max_bit = 0;
	
	while (max_rank > 0)
	{
		max_rank >>= 1;
		max_bit++;
	}
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->rank >> i) & 1)
				ra(stack_a, bench);
			else
				pb(stack_a, stack_b, bench);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, bench);
		i++;
	}	
}
