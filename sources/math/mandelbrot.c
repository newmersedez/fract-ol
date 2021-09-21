/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:43:42 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 21:19:59 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <stdio.h>

static unsigned int	get_color(int iteration, int max_iteration)
{
	double	t;
	int	red;
	int	green;
	int	blue;

	t = (double)iteration / (double)max_iteration;

	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return ((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF);
}

void	draw_mandelbrot(t_win *vars)
{
	unsigned int	color;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	z;
	int			max_iteration;
	int			iteration;
	int			x, y;

	min.re = -2.0;
	max.re = 2.0;
	min.im = -2.0;
	max.im = min.im + (max.re - min.re) * WIN_HEIGHT / WIN_WIDTH;
	factor.re = (max.re - min.re) / (WIN_WIDTH - 1);
	factor.im = (max.im - min.im) / (WIN_HEIGHT - 1);
	max_iteration = ITERATIONS;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		c.im = max.im - y * factor.im;
		x = 0;
		while (x < WIN_WIDTH)
		{
			c.re = min.re + x * factor.re;
			z = init_complex(c.re, c.im);
			iteration = 0;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				&& iteration < max_iteration)
			{
				z = init_complex(
                pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
                2.0 * z.re * z.im + c.im);
				iteration++;
			}
        	color = get_color(iteration, max_iteration);
			my_mlx_pixel_put(&vars->img, x, y, color);
			x++;
		}
		y++;
	}
	(void)vars;
}
