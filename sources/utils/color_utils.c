/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:20:47 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/27 20:38:51 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	get_color(int iteration, int max_iteration)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / (double)(1 + max_iteration);
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF));
}
