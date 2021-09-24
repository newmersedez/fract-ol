/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:35:33 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/24 21:30:50 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	mouse_interpolate(t_fractal *fractal, int x, int y, float zoom)
{
	int	x_interpolate;
	int	y_interpolate;

	x_interpolate = WIN_WIDTH / x;
	y_interpolate = WIN_HEIGHT / y;
	fractal->min.re += zoom * x_interpolate;
	fractal->min.im += zoom * y_interpolate;
	fractal->max.re -= zoom * x_interpolate;
	fractal->max.im = fractal->min.im + (fractal->max.re - fractal->min.re)
		* WIN_HEIGHT / WIN_WIDTH;
	fractal->factor.re = (fractal->max.re - fractal->min.re)
		/ (WIN_WIDTH - 1);
	fractal->factor.im = (fractal->max.im - fractal->min.im)
		/ (WIN_HEIGHT - 1);
}

void	mouse_zoom_in(t_fractal *fractal, int x, int y)
{
	float	zoom;

	zoom = 0.1;
	mouse_interpolate(fractal, x, y, zoom);
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}

void	mouse_zoom_out(t_fractal *fractal, int x, int y)
{
	float	zoom;

	zoom = -0.1;
	mouse_interpolate(fractal, x, y, zoom);
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}
