/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:22:51 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/27 20:15:23 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractol.h"

/* Structures */

typedef struct s_window
{
	void		*mlx;
	void		*win;
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
	int			min_pthread_bound;
	int			max_pthread_bound;
	int			max_iteration;
}	t_fractal;

/* Scene Utils */

t_window	create_window(int width, int height, char *title);
t_image		create_image(t_window window);
void		set_defaults(t_fractal *fractal);

/* Hook utils */

int			close_hook(t_fractal *vars);
int			expose_hook(t_fractal *fractal);
int			keyboard_hook(int keycode, t_fractal *vars);
int			mouse_hook(int keycode, int x, int y, t_fractal *fractal);

/* Control utils */

void		mouse_zoom_in(t_fractal *fractal, int x, int y);
void		mouse_zoom_out(t_fractal *fractal, int x, int y);
void		keyboard_move_up(t_fractal *fractal);
void		keyboard_move_down(t_fractal *fractal);
void		keyboard_move_left(t_fractal *fractal);
void		keyboard_move_right(t_fractal *fractal);
void		keyboard_less_iterations(t_fractal *fractal);
void		keyboard_more_iterations(t_fractal *fractal);

/* Draw utils */

void		my_mlx_pixel_put(t_image *data, int x, int y, int color);

/* Color utils */

int			get_color(int iteration, int max_iteration);

/* Fractal Drawing functions */

void		draw_mandelbrot(t_fractal *vars);
void		draw_julia(t_fractal *vars);

#endif