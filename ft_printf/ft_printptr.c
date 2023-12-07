/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:42:14 by rpliego           #+#    #+#             */
/*   Updated: 2023/05/22 17:42:16 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaux(int out, unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		out = ft_printaux(out, n / 16);
		if (out == -1)
			return (-1);
	}
	out = ft_printc(out, base[n % 16]);
	if (out == -1)
		return (-1);
	return (out);
}

int	ft_printptr(int out, void *ptr)
{
	out = ft_printstr(out, "0x");
	if (out == -1)
		return (-1);
	out = ft_printaux(out, (unsigned long long)ptr);
	if (out == -1)
		return (-1);
	return (out);
}
