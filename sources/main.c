/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:13:48 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/28 21:51:49 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (argc != 2)
		exit(EXIT_FAILURE);
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		fractal.fractal_type = MANDELBROT;
	else if (!ft_strcmp(argv[1], "Julia"))
		fractal.fractal_type = JULIA;
	else
		exit(EXIT_FAILURE);
	fractal.window = create_window(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	fractal.image = create_image(fractal.window);
	set_defaults(&fractal);
	draw_fractal(&fractal);
	mlx_hook(fractal.window.win, 4, 0, mouse_hook, &fractal);
	mlx_hook(fractal.window.win, 2, 5, keyboard_hook, &fractal);
	mlx_hook(fractal.window.win, 17, 0, close_hook, &fractal);
	mlx_loop(fractal.window.mlx);
	return (0);
}
