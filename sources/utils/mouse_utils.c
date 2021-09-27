/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:35:33 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/27 20:46:33 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	mouse_zoom_in(t_fractal *fractal, int x, int y)
{
	(void)x;
	(void)y;
	(void)fractal;
	printf("zoom in\n");
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	mouse_zoom_out(t_fractal *fractal, int x, int y)
{
	(void)x;
	(void)y;
	(void)fractal;
	printf("zoom out\n");
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}
