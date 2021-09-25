/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:50:47 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/25 15:38:38 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "fractol.h"

/* Window settings */

# define WIN_WIDTH			1000
# define WIN_HEIGHT 		1000
# define WIN_NAME			"fract-ol"
# define THREADS			50
# define ITERATIONS_START	25
# define ITERATIONS_CHANGE	5
# define ITERATIONS_MIN		10
# define ITERATIONS_MAX		50

/* Colors */

# define WHITE				0xFFFFFF
# define MARINE				0x0FFFF0

/* Mouse codes */

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	2
# define MOUSE_WHEEL_DOWN	2
# define MOUSE_SCROLL_UP 	4
# define MOUSE_SCROLL_DOWN 	5

/* Keyboard codes */

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W				13
# define KEY_Q				12	
# define KEY_E				14
# define KEY_ESC			53
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_UP				126

#endif
