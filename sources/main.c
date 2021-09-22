/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:13:48 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/22 20:51:25 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_fractal	*fractal;

	(void)argc;	
	(void)argv;

	fractal = (t_fractal *)malloc(sizeof (t_fractal));
	fractal->window = create_window(WIN_WIDTH, WIN_HEIGHT, "fractol");

	mlx_expose_hook(fractal->window.win, expose_hook, fractal);
	mlx_mouse_hook(fractal->window.win, mouse_hook, fractal);
	mlx_key_hook(fractal->window.win, escape_hook, fractal);
	mlx_hook(fractal->window.win, 17, 0, close_hook, fractal);
	mlx_loop(fractal->window.mlx);
	free(fractal);
}
