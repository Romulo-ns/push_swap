/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:46:39 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/27 14:25:09 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **src, t_stack **dest, t_bench *bench)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dest)
		(*dest)->prev = tmp;
	tmp->next = *dest;
	*dest = tmp;
	if (bench)
		bench->total_ops++;
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	write(1, "pb\n", 3);
	push(a, b, bench);
	if (bench)
		bench->pb++;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push(b, a, bench);
	write(1, "pa\n", 3);
	if (bench)
		bench->pa++;
}
