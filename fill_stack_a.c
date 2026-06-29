/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:47:00 by willpere          #+#    #+#             */
/*   Updated: 2026/06/29 16:30:20 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_all(char **args_matrix, int elements, t_stack **stack_a)
{
	free_split(args_matrix, elements);
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

void	fill_stack_a(t_stack **stack_a, int argc, char **argv, t_bench *bench)
{
	char		**args_matrix;
	int			elements;
	int			i;
	long long	number;

	args_matrix = parse_arguments(argc, argv, bench);
	if (!args_matrix)
		return ;
	elements = count_elements(args_matrix);
	if (!is_valid_number(args_matrix, elements))
		clear_all(args_matrix, elements, stack_a);
	i = 0;
	while (i < elements)
	{
		number = push_swap_atoi(args_matrix[i]);
		if ((number > INT_MAX || number < INT_MIN)
			|| check_duplicate(*stack_a, (int)number))
			clear_all(args_matrix, elements, stack_a);
		if (!stack_add_last(stack_a, number))
			clear_all(args_matrix, elements, stack_a);
		i++;
	}
	free_split(args_matrix, elements);
	set_rank(stack_a);
}
