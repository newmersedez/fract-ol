/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:21:13 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/23 22:14:09 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	escape_hook(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
		mlx_destroy_window(fractal->window.mlx, fractal->window.win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_hook(t_fractal *fractal)
{
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_destroy_window(fractal->window.mlx, fractal->window.win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	expose_hook(t_fractal *fractal)
{
	fractal->image = create_image(fractal->window);
	draw_mandelbrot(fractal);
	mlx_put_image_to_window(fractal->window.mlx, fractal->window.win, fractal->image.img, 0, 0);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_SCROLL_UP)
	{
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		expose_hook(fractal);
	}
	if (keycode == MOUSE_SCROLL_DOWN)
	{
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		expose_hook(fractal);
	}
	return (0);
}
