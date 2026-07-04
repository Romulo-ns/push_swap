/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willpere <willpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:48:09 by willpere          #+#    #+#             */
/*   Updated: 2026/07/04 10:26:35 by willpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_malloc(char *args)
{
	free(args);
	write(2, "Error\n", 6);
	exit(1);
}

char	**parse_arguments(int argc, char **argv, t_bench *bench)
{
	char	*args;
	char	**matrix;
	int		i;
	int		j;
	int		k;

	args = malloc(total_length(argc, argv) + 1 - bench->active);
	if (!args)
		return (NULL);
	i = 1;
	k = 0;
	if (bench)
		i += bench->active;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			free_malloc(args);
		while (argv[i][j])
			args[k++] = argv[i][j++];
		if (++i < argc)
			args[k++] = ' ';
	}
	args[k] = '\0';
	return (matrix = ft_split(args, ' '), free(args), matrix);
}
