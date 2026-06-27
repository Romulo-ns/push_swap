/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:51:44 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/27 16:17:44 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

// Macro definition

# define BENCH_MARK "--bench"
# define STRA_SIMPLE "--simple"
# define STRA_MEDIUM "--medium"
# define STRA_COMPLEX "--complex"
# define STRA_ADAPTIVE "--adaptive"

typedef struct s_stack
{
	int				value;
	int				index;
	int				rank;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


typedef struct s_bench
{
	int		active;
	double	disorder;
	char	*strategy;
	int		total_ops;
	int 	sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int 	rr;
	int		rra;
	int		rrb;
	int		rrr;
	
}	t_bench;

int			main(int argc, char **argv);
int			count_elements(char **args_matrix);
int			total_length(int argc, char **argv);
int			is_valid_number(char **args_matrix, int elements);
int			check_duplicate(t_stack *stack_a, int number);
int			stack_add_last(t_stack **stack_a, int number);
int			stack_size(t_stack *stack);
float		get_disorder(t_stack *stack);
long long	push_swap_atoi(const char *nptr);
char		**parse_arguments(int argc, char **argv);
void		fill_stack_a(t_stack **stack_a, int argc, char **argv);
void		free_split(char **result, size_t size);
void		free_stack(t_stack **stack_a);
void		sa(t_stack **stack_a, t_bench *bench);
void		sb(t_stack **stack_b, t_bench *bench);
void		ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void		pa(t_stack **a, t_stack **b, t_bench *bench);
void		pb(t_stack **a, t_stack **b, t_bench *bench);
void		ra(t_stack **a, t_bench *bench);
void		rb(t_stack **b, t_bench *bench);
void		rr(t_stack **a, t_stack **b, t_bench *bench);
void		rra(t_stack **stack, t_bench *bench);
void		rrb(t_stack **b, t_bench *bench);
void		rrr(t_stack **a, t_stack **b, t_bench *bench);
void		set_rank(t_stack **stack);
void		select_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
t_stack		*stack_last(t_stack *stack);		
void		view_stack(t_stack *stack);
void		insertion(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void		sort_three(t_stack **stack_a, t_bench *bench);
int			find_highest_rank(t_stack *stack_a);
void		putstr_fd(char *str, int fd);
void		putnbr_fd(int n, int fd);
void		bench_initiate(t_bench *bench);
void		print_benchmark(t_bench *bench);
void		print_benchmark_moves(t_bench *bench);

#endif
