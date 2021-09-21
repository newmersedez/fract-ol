/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:43:42 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 18:50:13 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	mandelbrot(t_win *vars)
{
	int	i;
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = 10;
	y1 = 10;
	x2 = 100;
	y2 = 100;
	i = x1;
	while (i < x2)
	{
		my_mlx_pixel_put(&vars->img, y1, i, 0xFFFFFF);
		my_mlx_pixel_put(&vars->img, y2, i, 0xFFFFFF);
		my_mlx_pixel_put(&vars->img, i, x1, 0xFFFFFF);
		my_mlx_pixel_put(&vars->img, i, x2, 0xFFFFFF);
		i++;
	}
}