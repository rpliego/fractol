/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:08:08 by rpliego           #+#    #+#             */
/*   Updated: 2023/05/20 20:08:09 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if(char c, va_list args, int out)
{
	if (c == 'c')
		out = ft_printc(out, va_arg(args, int));
	else if (c == 's')
		out = ft_printstr(out, va_arg(args, char *));
	else if (c == 'p')
		out = ft_printptr(out, va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		out = ft_printnbr(out, va_arg(args, long int));
	else if (c == 'u')
		out = ft_printunsigned(out, va_arg(args, unsigned int));
	else if (c == 'x')
		out = ft_printhexlow(out, va_arg(args, long int));
	else if (c == 'X')
		out = ft_printhexup(out, va_arg(args, long int));
	else if (c == '%')
		out = ft_printc(out, '%');
	else
		out = -1;
	return (out);
}

int	ft_find(const char *str, va_list args, int out)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			out = ft_if(str[i], args, out);
		}
		else
			out = ft_printc(out, str[i]);
		if (out == -1)
			return (-1);
		i++;
	}
	return (out);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		out;

	out = 0;
	va_start (ap, str);
	out = ft_find(str, ap, out);
	va_end (ap);
	return (out);
}
