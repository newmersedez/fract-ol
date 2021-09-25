/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:58:06 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/25 15:44:07 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	keyboard_move_right(t_fractal *fractal)
{
	printf("move right\n");
	fractal->min.re -= 0.1;
	fractal->max.re -= 0.1;
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}

void	keyboard_move_left(t_fractal *fractal)
{
	printf("move left\n");
	fractal->min.re += 0.1;
	fractal->max.re += 0.1;
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}

void	keyboard_move_up(t_fractal *fractal)
{
	printf("move up\n");
	fractal->min.im -= 0.1;
	fractal->max.im -= 0.1;
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}

void	keyboard_move_down(t_fractal *fractal)
{
	printf("move down\n");
	fractal->min.im += 0.1;
	fractal->max.im += 0.1;
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}

void	keyboard_less_iterations(t_fractal *fractal)
{
	printf("less iters\n");
	if (fractal->max_iteration - ITERATIONS_CHANGE >= ITERATIONS_MIN)
	{
		fractal->max_iteration -= ITERATIONS_CHANGE;
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		expose_hook(fractal);
	}
}

void	keyboard_more_iterations(t_fractal *fractal)
{
	printf("more iters\n");
	if (fractal->max_iteration + ITERATIONS_CHANGE <= ITERATIONS_MAX)
	{
		fractal->max_iteration += ITERATIONS_CHANGE;
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		expose_hook(fractal);
	}
}
