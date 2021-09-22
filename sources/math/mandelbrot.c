/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:43:42 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/22 16:04:13 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <stdio.h>

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
	max.im = min.im + (max.re - min.re) * WIN_HEIGHT / (WIN_WIDTH);
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
				z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re, 2.0 * z.re * z.im + c.im);
				iteration++;
			}
        	color = get_color(iteration, max_iteration);
			my_mlx_pixel_put(&vars->img, x, y, get_color(iteration, max_iteration));
			x++;
		}
		y++;
	}
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
