/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:26:19 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/25 14:08:30 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_highest_rank(t_stack *stack_a)
{
	int highest_rank;

	highest_rank = stack_a->rank;
	while (stack_a)
	{
		if (stack_a->rank > highest_rank)
			highest_rank = stack_a->rank;
		stack_a = stack_a->next;
	}
	return (highest_rank);
}

void	sort_three(t_stack **stack_a)
{	
	int last_rank = find_highest_rank(*stack_a);
	
	if ((*stack_a)->rank == last_rank)
		ra(stack_a);
	if ((*stack_a)->next->rank == last_rank)
		rra(stack_a);
	if ((*stack_a)->rank > (*stack_a)->next->rank)
		sa(stack_a);
}

void	push_to_b_by_rank(t_stack **stack_a, t_stack **stack_b, int stack_rank)
{
	t_stack *top_stack;
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
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	push_to_b_by_rank(stack_a, stack_b, 1);
	push_to_b_by_rank(stack_a, stack_b, 2);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);

}
void	select_sort(t_stack **stack_a, t_stack **stack_b)
{
	float	disorder;
	int		size;
	
	size = stack_size(*stack_a);
	disorder = get_disorder(*stack_a);
	
	if (disorder == 0)
		return ;
	if (size <= 5)
	{
		if (size == 2 && (*stack_a)->rank > (*stack_a)->next->rank)
			sa(stack_a);
		else if (size == 3)
			sort_three(stack_a);
		else if (size == 5 || size == 4)
			sort_five(stack_a, stack_b);
        return ;
    }
	else
	{
		insertion(stack_a, stack_b);
        return ;
	}
}
