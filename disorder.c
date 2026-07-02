/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:10:26 by romdo-na          #+#    #+#             */
/*   Updated: 2026/07/02 21:19:38 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	get_disorder(t_stack *stack)
{
	float	mistakes;
	float	pairs;
	t_stack	*copy;	

	mistakes = 0;
	pairs = 0;
	while (stack)
	{
		copy = stack->next;
		while (copy)
		{
			pairs++;
			if (stack->value > copy->value)
				mistakes++;
			copy = copy->next;
		}
		stack = stack->next;
	}
	return ((mistakes / pairs) * 100);
}
