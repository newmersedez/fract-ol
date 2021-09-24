/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:13:48 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/24 17:19:43 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	t_fractal	fractal;

	fractal.window = create_window(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	set_defaults(&fractal);
	mlx_expose_hook(fractal.window.win, expose_hook, &fractal);
	mlx_mouse_hook(fractal.window.win, mouse_hook, &fractal);
	mlx_key_hook(fractal.window.win, keyboard_hook, &fractal);
	mlx_hook(fractal.window.win, 17, 0, close_hook, &fractal);
	mlx_loop(fractal.window.mlx);
}
