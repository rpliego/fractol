/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:45:01 by rpliego           #+#    #+#             */
/*   Updated: 2023/11/30 13:41:39 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(double r, double i)
{
	int		n;
	double	x_aux;
	double	zr;
	double	zi;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITER)
	{
		x_aux = 2 * zr * zi + i;
		zr = (zr * zr) - (zi * zi) + r;
		zi = x_aux;
		n++;
		if ((zr * zr) + (zi * zi) > 4.0)
			return (n);
	}
	return (0);
}

int	calculate_julia(double r, double i, t_fractol *ft)
{
	int		n;
	double	aux;

	n = 0;
	aux = 0;
	while (n < MAX_ITER)
	{
		aux = 2 * r * i + ft->yj;
		r = (r * r) - (i * i) + ft->xj;
		i = aux;
		n++;
		if ((r * r) + (i * i) > 4.0)
			return (n);
	}
	return (0);
}
