/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:44:24 by rpliego           #+#    #+#             */
/*   Updated: 2023/11/30 14:26:27 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_aux(char *str, double out)
{
	double	div_dec;

	div_dec = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		out = out + (*str - '0') / div_dec;
		div_dec *= 10.0;
		str++;
	}
	if ((*str < '0' || *str > '9') && *str)
	{
		ft_printf("Try a valid number\n");
		exit(0);
	}
	return (out);
}

double	ft_atod(char *str, double out)
{
	int		neg;

	neg = 1;
	while ((*str == ' ' || *str == '\t') && *str)
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		out = out * 10.0 + (*str - '0');
		str++;
	}
	if ((*str < '0' || *str > '9') && *str != '.' && *str)
	{
		ft_printf("Try a valid number\n");
		exit(0);
	}
	if (*str == '.')
	{
		str++;
		out = ft_aux(str, out);
	}
	return (out * neg);
}

static int	check_jul(char *str)
{
	char	*jul;
	int		i;

	i = 0;
	jul = "Julia";
	while (str[i] && jul[i])
	{
		if (str[i] != jul[i])
			return (0);
		i++;
	}
	if (jul[i] == '\0')
		return (2);
	return (0);
}

static int	check_man(char *str)
{
	char	*man;
	int		i;

	i = 0;
	man = "Mandelbrot";
	while (str[i] && man[i])
	{
		if (str[i] != man[i])
			return (0);
		i++;
	}
	if (man[i] == '\0')
		return (1);
	return (0);
}

int	ft_check(char *str, char c)
{
	if (c == 'M')
		return (check_man(str));
	if (c == 'J')
		return (check_jul(str));
	return (0);
}
