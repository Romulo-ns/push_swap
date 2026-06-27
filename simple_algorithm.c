/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:24:11 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/27 15:25:50 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// • Insertion sort adaptation

int can_ra(t_stack *stack_a, int rank_b)
{
    int first_rank;
    int last_rank;

    first_rank = stack_a->rank;
    last_rank = stack_last(stack_a)->rank;

    if (last_rank < rank_b && rank_b < first_rank)
        return (1);

    if (last_rank > first_rank)
    {
        if (rank_b > last_rank || rank_b < first_rank)
            return (1);
    }
    return (0);
}

void insertion(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	size_a = stack_size(*stack_a);

    while (size_a > 3)
    {
        pb(stack_a, stack_b, bench);
        size_a--;
    }
    sort_three(stack_a, bench);
    while (*stack_b)
    {
        while (!can_ra(*stack_a, (*stack_b)->rank))
            ra(stack_a, bench);

        pa(stack_a, stack_b, bench);
    }
    while ((*stack_a)->rank != 1)
        ra(stack_a, bench);
}
