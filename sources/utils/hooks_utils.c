/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:21:13 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/27 19:58:32 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	keyboard_hook(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		keyboard_move_up(fractal);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		keyboard_move_down(fractal);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		keyboard_move_left(fractal);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		keyboard_move_right(fractal);
	else if (keycode == KEY_Q)
		keyboard_less_iterations(fractal);
	else if (keycode == KEY_E)
		keyboard_more_iterations(fractal);
	else if (keycode == KEY_ESC)
	{
		printf("exit with esc\n");
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
		mlx_destroy_window(fractal->window.mlx, fractal->window.win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_hook(t_fractal *fractal)
{
	printf("exit with red cross\n");
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
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 10, WHITE, "    Mandelbrot set    ");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 40, WHITE, "Controls - WASD/arrows");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 70, WHITE, "Zoom in - scroll up");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 90, WHITE, "(mouse left buton)");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 120, WHITE, "Zoom out - scroll down");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 140, WHITE, "(mouse right buton)");
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_LEFT_BUTTON)
		mouse_zoom_in(fractal, x, y);
	if (keycode == MOUSE_SCROLL_DOWN || keycode == MOUSE_RIGHT_BUTTON)
		mouse_zoom_out(fractal, x, y);
	return (0);
}
