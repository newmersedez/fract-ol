/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:50:26 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/30 16:51:14 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	success_exit(t_fractal *fractal)
{
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_destroy_window(fractal->window.mlx, fractal->window.win);
	exit(EXIT_SUCCESS);
}

void	fail_exit(t_fractal *fractal, char *message)
{
	if ((fractal->window.mlx || fractal->window.win)
		&& (fractal->image.img || fractal->image.addr))
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	if (fractal->window.mlx || fractal->window.win)
		mlx_destroy_window(fractal->window.mlx, fractal->window.win);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}
