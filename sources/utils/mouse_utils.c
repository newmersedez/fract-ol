/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:35:33 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/29 16:56:54 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	mouse_zoom_in(t_fractal *fractal, int x, int y)
{
	t_complex	mouse;
	(void)x;
	(void)y;
	(void)mouse;
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->max.re -= UPDATE * fractal->factor.re;
	fractal->min.re += UPDATE * fractal->factor.re;
	fractal->max.im -= UPDATE * fractal->factor.im;
	fractal->min.im += UPDATE * fractal->factor.im;
	// mouse.re = x * fractal->factor.re + fractal->min.re;
	// mouse.im = -1 * (y * fractal->factor.im + fractal->min.im);
	// fractal->max.re = (0.9 * fractal->max.re + 0.1 * mouse.re);
	// fractal->min.re = (0.9 * fractal->min.re + 0.1 * mouse.re);
	// fractal->max.im = (0.9 * fractal->max.im + 0.1 * mouse.im);
	// fractal->min.im = (0.9 * fractal->min.im + 0.1 * mouse.im);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	mouse_zoom_out(t_fractal *fractal)
{
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->max.re += UPDATE * fractal->factor.re;
	fractal->min.re -= UPDATE * fractal->factor.re;
	fractal->max.im += UPDATE * fractal->factor.im;
	fractal->min.im -= UPDATE * fractal->factor.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}
