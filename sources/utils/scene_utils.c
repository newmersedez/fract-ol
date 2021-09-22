/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:17:22 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/22 20:07:22 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_win	create_window(int width, int height, char *title)
{
	t_win	scene;

	scene.mlx = mlx_init();
	scene.height = height;
	scene.width = width;
	scene.win = mlx_new_window(scene.mlx, scene.width, scene.height, title);
	return (scene);
}

t_image	create_image(t_win window)
{
	t_image	image;

	image.img = mlx_new_image(window.mlx, window.width, window.height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	return (image);
}
