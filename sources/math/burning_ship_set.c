/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 22:04:34 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/28 22:37:04 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

# define ABS(x) (((x) < 0) ? (-x) : (x))

static int	iterate_burning_ship(t_fractal *fractal)
{
	t_complex	z;
	double		temp;
	int			iteration;

	iteration = 1;
	z.re = fractal->c.re;
	z.im = fractal->c.im;
	while (z.re * z.re + z.im * z.im <= 4.0
		&& iteration <= fractal->max_iteration)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + fractal->c.re;
		z.im = 2.0 * ABS(temp * z.im) + fractal->c.im;
		iteration++;
	}
	return (iteration);
}

static void	burning_ship_part(t_fractal *fractal)
{
	int	x;
	int	y;
	int	color;
	int	iteration;

	y = fractal->min_pthread_bound;
	while (y < fractal->max_pthread_bound)
	{
		fractal->c.im = fractal->max.im - y * fractal->factor.im;
		x = 0;
		while (x < WIN_WIDTH)
		{
			fractal->c.re = fractal->min.re + x * fractal->factor.re;
			iteration = iterate_burning_ship(fractal);
			color = get_color(iteration, fractal->max_iteration);
			my_mlx_pixel_put(&fractal->image, WIN_WIDTH - x - 1, WIN_HEIGHT - y - 1, color);
			x++;
		}
		y++;
	}
}

void	burning_ship(t_fractal *fractal)
{
	int			i;
	pthread_t	threads[THREADS];
	t_fractal	fractals[THREADS];

	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	i = 0;
	while (i < THREADS)
	{
		fractals[i] = *fractal;
		fractals[i].min_pthread_bound = i * (WIN_HEIGHT / THREADS);
		fractals[i].max_pthread_bound = (i + 1) * (WIN_HEIGHT / THREADS);
		pthread_create(&threads[i], NULL,
			(void *(*)(void *))burning_ship_part, (void *)&fractals[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}
