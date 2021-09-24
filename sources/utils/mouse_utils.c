/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:35:33 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/24 16:15:23 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <stdio.h>
// static void	mouse_coords_interpolate(int *x, int *y)
// {
	
// }

void	mouse_zoom_in(t_fractal *fractal, int x, int y)
{
	(void)x;
	(void)y;
	printf("zoom in\n");
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}

void	mouse_zoom_out(t_fractal *fractal, int x, int y)
{
	(void)x;
	(void)y;
	printf("zoom out\n");
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	expose_hook(fractal);
}
