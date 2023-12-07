/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:56:20 by rpliego           #+#    #+#             */
/*   Updated: 2023/05/23 17:56:21 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(int out, unsigned int n)
{
	if (n > 9)
	{
		out = ft_printunsigned(out, (n / 10));
		if (out == -1)
			return (-1);
	}
	out = ft_printc(out, (n % 10 + 48));
	return (out);
}
