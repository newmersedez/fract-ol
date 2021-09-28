/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:35:33 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/28 18:31:55 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	mouse_zoom_in(t_fractal *fractal, int x, int y)
{
	t_complex	mouse;

	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	mouse.re = x * ((fractal->max.re - fractal->min.re) / WIN_WIDTH) + fractal->min.re;
	mouse.im =  y * ((fractal->max.im - fractal->min.im) / WIN_HEIGHT) + fractal->min.im;

	double	zoom_factor	= 0.9;
	fractal->min.re = fractal->min.re * zoom_factor + mouse.re * (1 - zoom_factor);
	fractal->max.re = fractal->max.re * zoom_factor + mouse.re * (1 - zoom_factor);
	fractal->min.im = fractal->min.im * zoom_factor + mouse.im * (1 - zoom_factor);
	fractal->max.im = fractal->max.im * zoom_factor + mouse.im * (1 - zoom_factor);
	
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	mouse_zoom_out(t_fractal *fractal, int x, int y)
{
	t_complex	mouse;

	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	mouse.re = x * ((fractal->max.re - fractal->min.re) / WIN_WIDTH) + fractal->min.re;
	mouse.im =  y * ((fractal->max.im - fractal->min.im) / WIN_HEIGHT) + fractal->min.im;

	// fractal->min.re;
	// fractal->max.re;
	// fractal->min.im;
	// fractal->max.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}