/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:37:06 by willpere          #+#    #+#             */
/*   Updated: 2026/06/27 15:20:26 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack, t_bench *bench)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
	if (bench)
		bench->total_ops++;
}

void	sa(t_stack **stack_a, t_bench *bench)
{
	swap(stack_a, bench);
	write(1, "sa\n", 3);
		if (bench)
		bench->sa++;
}

void	sb(t_stack **stack_b, t_bench *bench)
{
	swap(stack_b, bench);
	write(1, "sb\n", 3);
		if (bench)
		bench->sb++;
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	swap(stack_a, bench);
	swap(stack_b, bench);
	write(1, "ss\n", 3);
		if (bench)
		bench->ss++;
}
