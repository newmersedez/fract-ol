/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:24:13 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/28 17:32:51 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_fractal(t_fractal *fractal)
{
	fractal->image = create_image(fractal->window);
	fractal->fractal_formula(fractal);
	mlx_put_image_to_window(fractal->window.mlx, fractal->window.win,
		fractal->image.img, 0, 0);
	// mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 10, WHITE,
	// 	"    Mandelbrot set    ");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 40, WHITE,
		"Controls - WASD/arrows");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 70, WHITE,
		"Zoom in - scroll up");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 90, WHITE,
		"(mouse left buton)");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 120, WHITE,
		"Zoom out - scroll down");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 140, WHITE,
		"(mouse right buton)");
	return (0);
}
