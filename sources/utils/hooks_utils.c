/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:21:13 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/23 21:23:21 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

// int	b = 100;

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

/* DELETE */
// void	draw_line(t_fractal *vars, int length)
// {
// 	int	i;

// 	i = 0;
// 	while (i < length)
// 	{
// 		my_mlx_pixel_put(&vars->image, i, 500, 0x0FFFF0);
// 		i++;
// 	}
// }

int	expose_hook(t_fractal *fractal)
{
	fractal->image = create_image(fractal->window);
	// draw_line(fractal, b);
	draw_mandelbrot(fractal);
	mlx_put_image_to_window(fractal->window.mlx, fractal->window.win, fractal->image.img, 0, 0);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	(void)keycode;
	(void)fractal;
	if (keycode == 4 || keycode == 1)
	{
		fractal->max.re -= 0.05;
		fractal->max.im -= 0.05;
		fractal->min.re += 0.05;
		fractal->min.im += 0.05;
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		expose_hook(fractal);
	}
	if (keycode == 5 || keycode == 2)
	{
		fractal->max.re += 0.5;
		fractal->max.im += 0.5;
		fractal->min.re -= 0.5;
		fractal->min.im -= 0.5;
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		expose_hook(fractal);
	}
	return (0);
}
