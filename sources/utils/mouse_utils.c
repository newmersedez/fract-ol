/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:35:33 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/28 16:16:51 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	mouse_zoom_in(t_fractal *fractal, int x, int y)
{
	t_complex	mouse;
	
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	mouse.re = (x - WIN_WIDTH / 2) * fractal->factor.re;
	mouse.im = (WIN_HEIGHT / 2 - y) * fractal->factor.im;
	
	
	fractal->min.re += mouse.re;
	fractal->max.re += mouse.re;
	fractal->min.im += mouse.im;
	fractal->max.im += mouse.im;


	fractal->min.re += UPDATE * fractal->factor.re;
	fractal->max.re -= UPDATE * fractal->factor.re;
	fractal->min.im += UPDATE * fractal->factor.im;
	fractal->max.im -= UPDATE * fractal->factor.im;
	
	printf("x = %f   y = %f\n", mouse.re, mouse.im);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	mouse_zoom_out(t_fractal *fractal, int x, int y)
{
	t_complex	mouse;

	(void)mouse;
	(void)x;
	(void)y;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}
