/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:35:33 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/29 22:07:20 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	mouse_zoom_in(t_fractal *fractal, int x, int y)
{
	t_complex	mouse;
	long double	zoom;

	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	mouse.re = (long double)x * fractal->factor.re + fractal->min.re;
	mouse.im = (long double)y * fractal->factor.im + fractal->min.im;
	zoom = 0.9f;
	fractal->max.re += (1 - zoom) * mouse.re;
	fractal->min.re += (1 - zoom) * mouse.re;
	fractal->max.im -= (1 - zoom) * mouse.im;
	fractal->min.im -= (1 - zoom) * mouse.im;

	fractal->max.re *= zoom;
	fractal->min.re *= zoom;
	fractal->max.im *= zoom;
	fractal->min.im *= zoom;
	// fractal->max.re = zoom * fractal->max.re + (1 - zoom) * mouse.re;
	// fractal->min.re = zoom * fractal->min.re + (1 - zoom) * mouse.re;
	// fractal->max.im = zoom * fractal->max.im + (1 - zoom) * mouse.im;
	// fractal->min.im = zoom * fractal->min.im + (1 - zoom) * mouse.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	mouse_zoom_out(t_fractal *fractal)
{
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->max.re += OFFSET * fractal->factor.re;
	fractal->min.re -= OFFSET * fractal->factor.re;
	fractal->max.im += OFFSET * fractal->factor.im;
	fractal->min.im -= OFFSET * fractal->factor.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}
