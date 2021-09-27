/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:58:06 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/27 21:29:55 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	keyboard_move_right(t_fractal *fractal)
{
	fractal->min.re += FPS * fractal->factor.re;
	fractal->max.re += FPS * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_left(t_fractal *fractal)
{
	fractal->min.re -= FPS * fractal->factor.re;
	fractal->max.re -= FPS * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_up(t_fractal *fractal)
{
	fractal->min.im += FPS * fractal->factor.re;
	fractal->max.im += FPS * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_down(t_fractal *fractal)
{
	fractal->min.im -= FPS * fractal->factor.re;
	fractal->max.im -= FPS * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_less_iterations(t_fractal *fractal)
{
	if (fractal->max_iteration - ITERATIONS_CHANGE >= ITERATIONS_MIN)
	{
		fractal->max_iteration -= ITERATIONS_CHANGE;
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
}

void	keyboard_more_iterations(t_fractal *fractal)
{
	if (fractal->max_iteration + ITERATIONS_CHANGE <= ITERATIONS_MAX)
	{
		fractal->max_iteration += ITERATIONS_CHANGE;
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
}
