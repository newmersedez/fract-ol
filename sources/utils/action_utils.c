/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:54:21 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/29 17:54:34 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	keyboard_julia_motion(t_fractal *fractal)
{
	if (fractal->is_julia_motion == OFF)
		fractal->is_julia_motion = ON;
	else if (fractal->is_julia_motion == ON)
		fractal->is_julia_motion = OFF;
}

void	keyboard_less_iterations(t_fractal *fractal)
{
	printf("less operations\n");
	if (fractal->max_iteration - ITERATIONS_CHANGE >= ITERATIONS_MIN)
	{
		fractal->max_iteration -= ITERATIONS_CHANGE;
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
}

void	keyboard_more_iterations(t_fractal *fractal)
{
	printf("more operations\n");
	if (fractal->max_iteration + ITERATIONS_CHANGE <= ITERATIONS_MAX)
	{
		fractal->max_iteration += ITERATIONS_CHANGE;
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
}
