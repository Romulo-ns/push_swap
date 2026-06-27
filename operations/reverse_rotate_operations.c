/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:25:24 by willpere          #+#    #+#             */
/*   Updated: 2026/06/27 15:05:35 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack, t_bench *bench)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	prev_last = last->prev;
	prev_last->next = NULL;
	last->prev = NULL; 
	(*stack)->prev = last; 
	last->next = *stack;
	*stack = last;
	if (bench)
		bench->total_ops++;
}

void	rra(t_stack **a, t_bench *bench)
{
	reverse_rotate(a, bench);
	write(1, "rra\n", 4);
	if (bench)
		bench->rra++;
}

void	rrb(t_stack **b, t_bench *bench)
{
	reverse_rotate(b, bench);	
	write(1, "rrb\n", 4);
	if (bench)
		bench->rrb++;
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	reverse_rotate(a, bench);
	reverse_rotate(b, bench);
	write(1, "rrr\n", 4);
	if (bench)
		bench->rrr++;
}
