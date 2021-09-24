/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:17:22 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/24 21:21:13 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_window	create_window(int width, int height, char *title)
{
	t_window	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, width, height, title);
	if (!window.mlx || !window.win)
		exit(EXIT_FAILURE);
	return (window);
}

t_image	create_image(t_window window)
{
	t_image	image;

	image.img = mlx_new_image(window.mlx, WIN_WIDTH, WIN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	if (!image.img || !image.addr)
		exit(EXIT_FAILURE);
	return (image);
}

void	set_defaults(t_fractal *fractal)
{
	fractal->min.re = -4.0;
	fractal->min.im = -4.0;
	fractal->max.re = 4.0;
	fractal->max.im = fractal->min.im + (fractal->max.re - fractal->min.re)
		* WIN_HEIGHT / WIN_WIDTH;
	fractal->factor.re = (fractal->max.re - fractal->min.re)
		/ (WIN_WIDTH - 1);
	fractal->factor.im = (fractal->max.im - fractal->min.im)
		/ (WIN_HEIGHT - 1);
	fractal->min_pthread_bound = 0;
	fractal->max_pthread_bound = WIN_HEIGHT / THREADS;
	fractal->max_iteration = ITERATIONS_START;
}
