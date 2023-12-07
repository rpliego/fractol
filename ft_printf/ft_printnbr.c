/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:05:57 by rpliego           #+#    #+#             */
/*   Updated: 2023/05/22 20:05:58 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int out, int x)
{
	long	n;

	n = x;
	if (n < 0)
	{
		n = n * (-1);
		out = ft_printc(out, '-');
		if (out == -1)
			return (-1);
	}
	if (n > 9)
	{
		out = ft_printnbr(out, (n / 10));
		if (out == -1)
			return (-1);
	}
	out = ft_printc(out, (n % 10 + 48));
	if (out == -1)
		return (-1);
	return (out);
}
