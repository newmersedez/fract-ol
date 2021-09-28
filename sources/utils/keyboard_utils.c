/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:58:06 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/28 21:50:24 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	keyboard_move_right(t_fractal *fractal)
{
	printf("move right\n");
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.re += UPDATE * fractal->factor.re;
	fractal->max.re += UPDATE * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_left(t_fractal *fractal)
{
	printf("move left\n");
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.re -= UPDATE * fractal->factor.re;
	fractal->max.re -= UPDATE * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_up(t_fractal *fractal)
{
	printf("move up\n");
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.im += UPDATE * fractal->factor.im;
	fractal->max.im += UPDATE * fractal->factor.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_down(t_fractal *fractal)
{
	printf("move down\n");
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.im -= UPDATE * fractal->factor.im;
	fractal->max.im -= UPDATE * fractal->factor.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_less_iterations(t_fractal *fractal)
{
	printf("less operations\n");
	if (fractal->max_iteration - ITERATIONS_CHANGE >= ITERATIONS_MIN)
	{
		fractal->max_iteration -= ITERATIONS_CHANGE;
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
}

void	keyboard_more_iterations(t_fractal *fractal)
{
	printf("more operations\n");
	if (fractal->max_iteration + ITERATIONS_CHANGE <= ITERATIONS_MAX)
	{
		fractal->max_iteration += ITERATIONS_CHANGE;
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
}
