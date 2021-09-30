/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:22:51 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/30 17:38:34 by lorphan          ###   ########.fr       */
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

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	t_window	window;
	t_image		image;
	t_complex	c;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	int			colorset;
	int			fractal_type;
	int			max_iteration;
	int			is_julia_motion;
	int			min_pthread_bound;
	int			max_pthread_bound;
}	t_fractal;

/* Scene functions */

t_window	create_window(int width, int height, char *title);
t_image		create_image(t_fractal *fractal);
void		init_application_from_args(t_fractal *fractal,
				int argc, char *argv[]);
void		set_defaults(t_fractal *fractal);
void		success_exit(t_fractal *fractal);
void		fail_exit(t_fractal *fractal, char *message);

/* Hook functions */

int			close_hook(t_fractal *fractal);
int			draw_fractal(t_fractal *fractal);
int			keyboard_hook(int keycode, t_fractal *fractal);
int			mouse_hook(int keycode, int x, int y, t_fractal *fractal);

/* Control functions */

void		mouse_zoom_out(t_fractal *fractal);
void		mouse_zoom_in(t_fractal *fractal, int x, int y);
int			mouse_motion_hook(int x, int y, t_fractal *fractal);
void		keyboard_move_up(t_fractal *fractal);
void		keyboard_move_down(t_fractal *fractal);
void		keyboard_move_left(t_fractal *fractal);
void		keyboard_move_right(t_fractal *fractal);
void		keyboard_julia_motion(t_fractal *fractal);
void		keyboard_less_iterations(t_fractal *fractal);
void		keyboard_more_iterations(t_fractal *fractal);
void		keyboard_change_colorset(int keycode, t_fractal *fractal);

/* Draw functions */

void		display_application_tips(void);
void		display_control_tips(t_fractal *fractal);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
int			get_color(t_fractal *fractal, int iteration, int max_iteration);

/* Fractal functions */

void		julia(t_fractal *fractal);
void		mandelbrot(t_fractal *fractal);
void		burning_ship(t_fractal *fractal);
void		tricorn(t_fractal *fractal);

#endif