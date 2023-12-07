/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:32:33 by rpliego           #+#    #+#             */
/*   Updated: 2023/11/30 14:33:13 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(t_fractol *ft)
{
	mlx_destroy_image(ft->mlx, ft->img);
	mlx_clear_window(ft->mlx, ft->mlx_win);
	mlx_destroy_window(ft->mlx, ft->mlx_win);
	exit(0);
}

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	esc(int key, t_fractol *ft)
{
	if (key == ESC_KEY)
		ft_exit(ft);
	return (1);
}

int	ft_zoom(int key, int x, int y, t_fractol *ft)
{
	x = 0;
	y = 0;
	if (key == SCROLLUP_KEY)
		ft->zoom *= 1.2;
	if (key == SCROLLDOWN_KEY)
		ft->zoom *= 0.8;
	mlx_clear_window(ft->mlx, ft->mlx_win);
	draw_fractol(ft, 0);
	return (0);
}

void	init(t_fractol *ft)
{
	ft->mlx = mlx_init();
	ft->mlx_win = mlx_new_window(ft->mlx, ANCHO, ALTO, "Fractol");
	ft->img = mlx_new_image(ft->mlx, ANCHO, ALTO);
	ft->addr = mlx_get_data_addr(ft->img, &ft->bits_per_pixel,
			&ft->line_length, &ft->endian);
}
