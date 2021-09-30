/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:17:22 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/30 14:26:31 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_window	create_window(int width, int height, char *title)
{
	t_window	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, width, height, title);
	if (!window.mlx || !window.win)
		fail_exit(NULL, INIT_WINDOW_ERROR);
	return (window);
}

t_image	create_image(t_fractal *fractal)
{
	t_image	image;

	if (!fractal)
		fail_exit(fractal, INIT_WINDOW_ERROR);
	image.img = mlx_new_image(fractal->window.mlx,
			WIN_WIDTH, WIN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img,
			&image.bits_per_pixel, &image.line_length,
			&image.endian);
	if (!image.img || !image.addr)
		fail_exit(fractal, INIT_IMAGE_ERROR);
	return (image);
}

void	set_defaults(t_fractal *fractal)
{
	fractal->c.re = -0.4;
	fractal->c.im = 0.6;
	fractal->min.re = -2.0;
	fractal->max.re = 2.0;
	fractal->min.im = -2.0;
	fractal->max.im = 2.0;
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->colorset = COLORSET_GALACTIC;
	fractal->max_iteration = ITERATIONS_START;
	fractal->is_julia_motion = OFF;
	fractal->min_pthread_bound = 0;
	fractal->max_pthread_bound = WIN_HEIGHT / THREADS;
}

void	init_application_from_args(t_fractal *fractal, int argc, char *argv[])
{
	if (argc != 2)
	{
		display_application_tips();
		fail_exit(fractal, ARGUMENTS_ERROR);
	}
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		fractal->fractal_type = MANDELBROT;
	else if (!ft_strcmp(argv[1], "Julia"))
		fractal->fractal_type = JULIA;
	else if (!ft_strcmp(argv[1], "Burning_ship"))
		fractal->fractal_type = BURNING_SHIP;
	else
	{
		display_application_tips();
		fail_exit(fractal, ARGUMENTS_ERROR);
	}
}
