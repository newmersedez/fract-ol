/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:13:48 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/30 14:26:31 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	init_application_from_args(&fractal, argc, argv);
	fractal.window = create_window(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	fractal.image = create_image(&fractal);
	set_defaults(&fractal);
	draw_fractal(&fractal);
	mlx_hook(fractal.window.win, 6, 6, mouse_motion_hook, &fractal);
	mlx_hook(fractal.window.win, 4, 0, mouse_hook, &fractal);
	mlx_hook(fractal.window.win, 2, 5, keyboard_hook, &fractal);
	mlx_hook(fractal.window.win, 17, 0, close_hook, &fractal);
	mlx_loop(fractal.window.mlx);
	success_exit(&fractal);
	return (0);
}
