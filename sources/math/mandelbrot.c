/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:43:42 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/24 21:32:29 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	iterate_mandelbrot(t_fractal *fractal)
{
	t_complex	z;
	int			iteration;

	iteration = 0;
	z = init_complex(fractal->c.re, fractal->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < fractal->max_iteration)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractal->c.re, 2.0 * z.re * z.im + fractal->c.im);
		iteration++;
	}
	return (iteration);
}

static void	draw_mandelbrot_part(t_fractal *fractal)
{
	int			x;
	int			y;
	int			top_bound;
	int			iteration;

	y = fractal->min_pthread_bound;
	top_bound = fractal->max_pthread_bound;
	while (y < top_bound)
	{
		x = 0;
		fractal->c.im = fractal->max.im - y * fractal->factor.im;
		while (x < WIN_WIDTH)
		{
			fractal->c.re = fractal->min.re + x * fractal->factor.re;
			iteration = iterate_mandelbrot(fractal);
			my_mlx_pixel_put(&fractal->image, x, y, get_color(iteration, fractal->max_iteration));
			x++;
		}
		y++;
	}
}

void draw_mandelbrot(t_fractal *fractal)
{
	int			i;
	int			step;
	pthread_t	pthreads[THREADS];
	t_fractal	fractals[THREADS];

	i = 0;
	step = WIN_HEIGHT / THREADS;
	while (i < THREADS)
	{
		fractals[i] = *fractal;
		fractals[i].min_pthread_bound = i * step;
		fractals[i].max_pthread_bound = (i + 1) * step;
		pthread_create(&pthreads[i], NULL, (void *(*)(void *))draw_mandelbrot_part, (void *)&fractals[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(pthreads[i], NULL);
}
