/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaaaaa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:53:34 by romdo-na          #+#    #+#             */
/*   Updated: 2026/06/27 14:54:07 by romdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write (fd, "-", 1);
		nbr = -(nbr);
	}
	if (nbr > 9)
		ft_putnbr_fd (nbr / 10, fd);
	write (fd, &"0123456789"[nbr % 10], 1);
}