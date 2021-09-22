/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:17:22 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/22 15:15:59 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_win	create_scene(int width, int height, char *title)
{
	t_win	vars;

	vars.mlx = mlx_init();
	vars.height = height;
	vars.width = width;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, title);
	vars.img.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	return (vars);
}
