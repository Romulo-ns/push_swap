/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:24:11 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/24 19:29:35 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// • Insertion sort adaptation


void insertion(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a = stack_size(*stack_a);

    set_rank(stack_a);
    while (size_a > 3)
    {
        pb(stack_a, stack_b);
        size_a--;
    }
    sort_three(stack_a);
    while (*stack_b)
    {
        // while ((*stack_a)->rank < (*stack_b)->rank && 
        //     stack_last(*stack_a)->rank > (*stack_b)->rank)
        //     ra(stack_a);
        // while ((*stack_a)->rank > (*stack_b)->rank && 
        //     stack_last(*stack_a)->rank > (*stack_b)->rank)
        //     ra(stack_a);
        // while ((*stack_a)->rank < (*stack_b)->rank && 
        //     stack_last(*stack_a)->rank < (*stack_b)->rank)
        //     ra(stack_a);
        while (!((*stack_a)->rank > (*stack_b)->rank) && 
            !(stack_last(*stack_a)->rank < (*stack_b)->rank))
            ra(stack_a);
        
        pa(stack_a, stack_b);
    }
    while ((*stack_a)->rank != 1)
        ra(stack_a);
}