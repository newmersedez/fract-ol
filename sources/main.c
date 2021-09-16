/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:13:48 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/16 20:52:37 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_rectangle(t_data *img, int x1, int y1, int x2, int y2)
{
	int	i;

	i = x1;
	while (i < x2)
	{
		my_mlx_pixel_put(img, y1, i, 0x00FF0000);
		my_mlx_pixel_put(img, y2, i, 0x00FF0000);
		my_mlx_pixel_put(img, i, x1, 0x00FF0000);
		my_mlx_pixel_put(img, i, x2, 0x00FF0000);
		i++;
	}
}

void	draw_cube(t_data *img, int x1, int y1, int x2, int y2)
{
		int	i;

	i = x1;
	while (i < x2)
	{
		my_mlx_pixel_put(img, y1, i, 0x00FF0000);
		my_mlx_pixel_put(img, y2, i, 0x00FF0000);
		my_mlx_pixel_put(img, i, x1, 0x00FF0000);
		my_mlx_pixel_put(img, i, x2, 0x00FF0000);
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_rectangle(&img, 0, 0, 100, 100);
	draw_cube(&img, 100, 100, 30);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
