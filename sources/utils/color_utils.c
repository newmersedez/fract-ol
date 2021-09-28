/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:20:47 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/28 22:17:45 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	get_color(int iteration, int max_iteration)
{
	// double	t;
	int		red;
	int		green;
	int		blue;

	// t = (double)iteration / (double)(1 + max_iteration);
	// red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	// green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	// blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
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
