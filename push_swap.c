/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willpere <willpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:29:38 by willpere          #+#    #+#             */
/*   Updated: 2026/07/02 21:27:05 by romdo-na         ###   ########.fr       */
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
	select_strategy(argc, argv, &bench);
	fill_stack_a(&stack_a, argc, argv, &bench);
	select_sort(&stack_a, &stack_b, &bench);
	free_stack(&stack_a);
	if ((&bench)->print_bench != 0)
		print_benchmark(&bench);
	return (0);
}
