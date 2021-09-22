/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:21:13 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/22 20:57:20 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <stdio.h>
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

int	mouse_hook(int keycode, t_fractal *fractal)
{
	(void)fractal;
	(void)keycode;
	printf("%d\n", (int)fractal);
	if (keycode == 4)
	{
		printf("zoom in\n");
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		expose_hook(fractal);
	}
	return (0);
}
