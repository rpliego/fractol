/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:52 by rpliego           #+#    #+#             */
/*   Updated: 2023/11/30 15:21:04 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# define ESC_KEY 53

# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5

# define MAX_ITER 40
# define ALTO 800
# define ANCHO 800

typedef struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x;
	double	y;
	int		max_iter;
	double	zoom;
	int		ftnb;
	double	xj;
	double	yj;
}				t_fractol;

int		ft_check(char *str, char c);
void	init(t_fractol *ft);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void	draw_fractol(t_fractol *ft, int i);
int		ft_zoom(int key, int x, int y, t_fractol *fractol);
int		esc(int key, t_fractol *ft);
int		ft_exit(t_fractol *ft);
int		calculate_mandelbrot(double r, double i);
int		calculate_julia(double r, double i, t_fractol *ft);
double	ft_atod(char *str, double out);

#endif