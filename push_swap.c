/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:29:38 by willpere          #+#    #+#             */
/*   Updated: 2026/06/24 20:01:40 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start(t_bench **movements)
{
	(*movements)->pa = 0;
	(*movements)->pb = 0;
	(*movements)->sa = 0;
	(*movements)->sb = 0;
	(*movements)->ss = 0;
	(*movements)->ra = 0;
	(*movements)->rb = 0;
	(*movements)->rr = 0;
	(*movements)->rra = 0;
	(*movements)->rrb = 0;
	(*movements)->rrr = 0;
}

void	view_stack(t_stack *stack)
{	
	t_stack	*current;

	current = stack;
	if (!current)
		printf("The stack is empty!\n");
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;		
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// moves	*movements;

	// start(&movements);
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	fill_stack_a(&stack_a, argc, argv);
	printf("fill_stack:\n");
	view_stack(stack_a);
	select_sort(&stack_a, &stack_b);
	printf("Stack B->\n");
	view_stack(stack_b);
	printf("Stack A->\n");
	view_stack(stack_a);
	free_stack(&stack_a);
	return (0);
}
