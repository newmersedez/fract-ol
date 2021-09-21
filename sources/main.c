/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:13:48 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 16:34:09 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	t_win	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "fract-ol");
	vars.img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_key_hook(vars.win, esc_button_pressed, &vars);
	mlx_hook(vars.win, 17, (1L << 17), red_cross_pressed, &vars);
	mlx_loop(vars.mlx);
}
