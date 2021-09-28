/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:17:50 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/28 17:34:24 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	julia(t_fractal *fractal)
{
	t_complex	z;
	int			x;
	int			y;
	int			temp;
	int			color;
	int			iteration;

	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		fractal->c.im = fractal->max.im - y * fractal->factor.im;
		while (y < WIN_HEIGHT)
		{
			fractal->c.re = fractal->min.re + x * fractal->factor.re;
   			iteration = 1;
			z.re = x * fractal->factor.re;
			z.im = y * fractal->factor.im;
			while (z.re * z.re + z.im * z.im <= 4.0 && iteration <= fractal->max_iteration)
			{
				temp = z.re;
				z.re = z.re * z.re - z.im * z.im + fractal->c.re;
				z.im = 2.0 * temp * z.im + fractal->c.im;
				iteration++;
			}
			color = get_color(iteration, fractal->max_iteration);
			my_mlx_pixel_put(&fractal->image, x, y, color);
			y++;
		}
		x++;
	}
}
