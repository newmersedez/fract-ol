/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:20:47 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/30 13:43:16 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	set_colorset_galactic(int iteration, int max_iteration)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (iteration >= max_iteration)
	{
		red = 80;
		green = 0;
		blue = 20;
	}
	else
	{	
		t = (double)iteration / (double)(1 + max_iteration);
		red = (int)(9 * (1 - t) * pow(t, 3) * 255);
		green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	return (((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF));
}

static int	set_colorset_green(int iteration, int max_iteration)
{
	int		red;
	int		green;
	int		blue;

	if (iteration >= max_iteration)
	{
		red = 20;
		green = 30;
		blue = 30;
	}
	else
	{
		red = (iteration * 6) % 255;
		green = (iteration * 10) % 255;
		blue = (iteration * 12) % 255;
	}
	return (((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF));
}

static int	set_colorset_red(int iteration, int max_iteration)
{
	int		red;
	int		green;
	int		blue;

	if (iteration >= max_iteration)
	{
		red = 141;
		green = 26;
		blue = 187;
	}
	else
	{
		red = (iteration * 12) % 255;
		green = (iteration * 2) % 255;
		blue = (iteration * 6) % 255;
	}
	return (((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF));
}

int	get_color(t_fractal *fractal, int iteration, int max_iteration)
{
	int	color;

	color = 0;
	if (fractal->colorset == COLORSET_GALACTIC)
		color = set_colorset_galactic(iteration, max_iteration);
	else if (fractal->colorset == COLORSET_GREEN)
		color = set_colorset_green(iteration, max_iteration);
	else if (fractal->colorset == COLORSET_RED)
		color = set_colorset_red(iteration, max_iteration);
	return (color);
}
