/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:15:06 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 16:35:39 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Window size */

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

/* Keycodes */

# define KEY_ESC 53

/* Headers */

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

/* Structures */

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
	void	*mlx;
	void	*win;
	t_image	img;
}	t_win;

/* Function prototypes */

int		red_cross_pressed(t_win *vars);
int		esc_button_pressed(int keycode, t_win *vars);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

#endif