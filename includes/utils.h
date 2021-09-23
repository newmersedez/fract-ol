/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:22:51 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/23 20:55:36 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractol.h"

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
}	t_window;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_fractal
{
	t_image		image;
	t_window	window;
	t_complex	c;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	int			max_iteration;
}	t_fractal;

t_window	create_window(int width, int height, char *title);
t_image		create_image(t_window window);
void		set_defaults(t_fractal *fractal);

int			close_hook(t_fractal *vars);
int			escape_hook(int keycode, t_fractal *vars);
int			mouse_hook(int keycode, int x, int y, t_fractal *fractal);
int			expose_hook(t_fractal *fractal);

void		my_mlx_pixel_put(t_image *data, int x, int y, int color);

int			get_red(int trgb);
int			get_green(int trgb);
int			get_blue(int trgb);
int			get_color(int iteration, int max_iteration);

void		draw_mandelbrot(t_fractal *vars);
void		draw_julia(t_fractal *vars);

#endif