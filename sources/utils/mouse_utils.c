/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:35:33 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/24 22:17:23 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void	mouse_interpolate(t_fractal *fractal, int x, int y, float zoom)
{
	t_complex	mouse;
	double		interpolation;

	mouse = init_complex(
		(double)x / (WIN_WIDTH / (fractal->max.re - fractal->min.re))
			+ fractal->min.re,
		(double)y / (WIN_HEIGHT / (fractal->max.im - fractal->min.im))
			* -1 + fractal->max.im);
	interpolation = 1.0 / zoom;
	fractal->min.re = interpolate(mouse.re, fractal->min.re, interpolation);
	fractal->min.im = interpolate(mouse.im, fractal->min.im, interpolation);
	fractal->max.re = interpolate(mouse.re, fractal->max.re, interpolation);
	fractal->max.im = interpolate(mouse.im, fractal->max.im, interpolation);
}

void	mouse_zoom_in(t_fractal *fractal, int x, int y)
{
	float	zoom;

	zoom = 1.2;
	mouse_interpolate(fractal, x, y, zoom);
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}

void	mouse_zoom_out(t_fractal *fractal, int x, int y)
{
	float	zoom;

	zoom = 0.8;
	mouse_interpolate(fractal, x, y, zoom);
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}
