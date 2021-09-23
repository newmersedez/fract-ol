/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:43:42 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/23 20:59:48 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <stdio.h>

void	draw_mandelbrot(t_fractal *fractal)
{
	t_complex	z;
	int			x, y;
	int			color;
	int			iteration;

	
	y = 0;
	while (y < WIN_HEIGHT)
	{
		fractal->c.im = fractal->max.im - y * fractal->factor.im;
		x = 0;
		while (x < WIN_WIDTH)
		{
			fractal->c.re = fractal->min.re + x * fractal->factor.re;
			z = init_complex(fractal->c.re, fractal->c.im);
			iteration = 0;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				&& iteration < fractal->max_iteration)
			{
				z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
					+ fractal->c.re, 2.0 * z.re * z.im + fractal->c.im);
				iteration++;
			}
        	color = get_color(iteration, fractal->max_iteration);
			my_mlx_pixel_put(&fractal->image, x, y, get_color(iteration, fractal->max_iteration));
			x++;
		}
		y++;
	}
}
