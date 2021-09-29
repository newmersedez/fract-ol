/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:58:06 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/29 22:02:53 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	keyboard_move_right(t_fractal *fractal)
{
	printf("move right\n");
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.re += OFFSET * fractal->factor.re;
	fractal->max.re += OFFSET * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_left(t_fractal *fractal)
{
	printf("move left\n");
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.re -= OFFSET * fractal->factor.re;
	fractal->max.re -= OFFSET * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_up(t_fractal *fractal)
{
	printf("move up\n");
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.im += OFFSET * fractal->factor.im;
	fractal->max.im += OFFSET * fractal->factor.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_down(t_fractal *fractal)
{
	printf("move down\n");
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.im -= OFFSET * fractal->factor.im;
	fractal->max.im -= OFFSET * fractal->factor.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}
