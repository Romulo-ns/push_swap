/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:24:11 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/24 20:32:59 by romdo-na         ###   ########.fr       */
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
        printf("stack_b: %d, rank: %d\n", (*stack_b)->value ,(*stack_b)->rank);
        printf("stack_a: %d, rank: %d\n", (*stack_a)->value ,(*stack_a)->rank);
        // while ((*stack_a)->rank < (*stack_b)->rank && 
        //     stack_last(*stack_a)->rank > (*stack_b)->rank)
        //     ra(stack_a);
        // while ((*stack_a)->rank > (*stack_b)->rank && 
        //     stack_last(*stack_a)->rank > (*stack_b)->rank)
        //     ra(stack_a);
        // while ((*stack_a)->rank < (*stack_b)->rank && 
        //     stack_last(*stack_a)->rank < (*stack_b)->rank)
        //     ra(stack_a);
        while (stack_last(*stack_a)->rank < (*stack_b)->rank &&
                (*stack_b)->rank < (*stack_a)->rank)
        {
            printf("Stack B..\n");
            view_stack(*stack_b);
            printf("Stack A..\n");
            view_stack(*stack_a);
            ra(stack_a);
        }
        
        pa(stack_a, stack_b);
    }
    while ((*stack_a)->rank != 1)
        ra(stack_a);
}