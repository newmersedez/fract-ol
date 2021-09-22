/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:22:51 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/22 20:43:06 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractol.h"

typedef struct s_win
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
}	t_win;

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
	t_win		window;
	t_image		image;
	t_complex	factor;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	int			max_iteration;
}	t_fractal;

t_win	create_window(int width, int height, char *title);
t_image	create_image(t_win window);

int		close_hook(t_fractal *vars);
int		escape_hook(int keycode, t_fractal *vars);
int		mouse_hook(int keycode, t_fractal *fractal);
int		expose_hook(t_fractal *fractal);

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

int		get_red(int trgb);
int		get_green(int trgb);
int		get_blue(int trgb);
int		get_color(int iteration, int max_iteration);

void	draw_mandelbrot(t_fractal *vars);
void	draw_julia(t_fractal *vars);

#endif