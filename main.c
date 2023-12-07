/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:05:28 by rpliego           #+#    #+#             */
/*   Updated: 2023/11/30 14:41:18 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_fractol *ft, int i)
{
	ft->x = 0;
	while (ft->x < ALTO)
	{
		ft->y = 0;
		while (ft->y < ANCHO)
		{
			if (ft->ftnb == 1)
				i = calculate_mandelbrot(ft->zoom * -2.5 + ft->x
						* ft->zoom * 5 / ALTO,
						ft->zoom * 2.5 + ft->y * ft->zoom * -5 / ANCHO);
			if (ft->ftnb == 2)
				i = calculate_julia(-2.5 * ft->zoom + ft->x
						* ft->zoom * 5 / ALTO,
						2.5 * ft->zoom + ft->y * ft->zoom * -5 / ANCHO, ft);
			if (i == 0)
				my_mlx_pixel_put(ft, ft->x, ft->y, 0x000000);
			else if (i > 0)
				my_mlx_pixel_put(ft, ft->x, ft->y, (0xFFAAA1 * i));
			ft->y++;
		}
		ft->x++;
	}
	mlx_put_image_to_window(ft->mlx, ft->mlx_win, ft->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fractol	ft;

	if (ac == 1)
		return (ft_printf("Try:\n-Julia || Mandelbrot\n"));
	ft.ftnb = ft_check(av[1], av[1][0]);
	if (ft.ftnb != 1 && ft.ftnb != 2)
		return (ft_printf("Try:\n-Julia || Mandelbrot\n"));
	if (ft.ftnb == 2 && ac != 4)
		return (ft_printf("Try:\n-Julia and 2 valid numbers\n"));
	if (ft.ftnb == 1 && ac != 2)
		return (ft_printf("Try:\n-Mandelbrot with no arguments\n"));
	if (ac == 4)
	{
		ft.xj = ft_atod(av[2], 0.0);
		ft.yj = ft_atod(av[3], 0.0);
	}
	ft.zoom = 1;
	init(&ft);
	draw_fractol(&ft, 0);
	mlx_hook(ft.mlx_win, 2, 0, esc, &ft);
	mlx_mouse_hook(ft.mlx_win, ft_zoom, &ft);
	mlx_hook(ft.mlx_win, 17, 0, ft_exit, &ft);
	mlx_loop(ft.mlx);
	return (0);
}
