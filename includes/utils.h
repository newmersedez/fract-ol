/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:22:51 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/22 17:02:27 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractol.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	t_image		img;
	int			height;
	int			width;
}	t_win;

t_win	create_scene(int width, int height, char *title);
int		red_cross_pressed(t_win *vars);
int		esc_button_pressed(int keycode, t_win *vars);
int		scroll_hook(int keycode, t_win *vars);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
int		get_red(int trgb);
int		get_green(int trgb);
int		get_blue(int trgb);
int		get_color(int iteration, int max_iteration);
void	draw_mandelbrot(t_win *vars);
void	draw_julia(t_win *vars);

#endif