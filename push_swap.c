/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:29:38 by willpere          #+#    #+#             */
/*   Updated: 2026/06/27 15:32:21 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_bench	bench;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	bench_initiate(&bench);
	fill_stack_a(&stack_a, argc, argv);
	printf("fill_stack:\n");
	view_stack(stack_a);
	select_sort(&stack_a, &stack_b, &bench);
	printf("Stack B->\n");
	view_stack(stack_b);
	printf("Stack A->\n");
	view_stack(stack_a);
	free_stack(&stack_a);
	print_benchmark(&bench);
	return (0);
}
