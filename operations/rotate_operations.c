/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:53:02 by willpere          #+#    #+#             */
/*   Updated: 2026/07/02 21:16:13 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack, t_bench *bench)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	first->prev = last;
	last->next = first;
	first->next = NULL;
	if (bench)
		bench->total_ops++;
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a, bench);
	write(1, "ra\n", 3);
	if (bench)
		bench->ra++;
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b, bench);
	write(1, "rb\n", 3);
	if (bench)
		bench->rb++;
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate(a, bench);
	rotate(b, bench);
	write(1, "rr\n", 3);
	if (bench)
		bench->rr++;
}
