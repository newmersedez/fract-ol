/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:50:47 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/30 13:35:46 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "fractol.h"

/* Window defaults */

# define WIN_WIDTH			1024
# define WIN_HEIGHT 		1024
# define OFFSET				60
# define WIN_NAME			"fract-ol"
# define OFF				0	
# define ON					1	

/* Threads defaults */
# define THREADS			8
# define ITERATIONS_START	32
# define ITERATIONS_CHANGE	8
# define ITERATIONS_MIN		10
# define ITERATIONS_MAX		256

/* Fractals math */

# define MANDELBROT			0
# define JULIA				1
# define BURNING_SHIP		2

/* Colors */

# define WHITE				0xFFFFFF
# define COLORSET_GALACTIC	0
# define COLORSET_GREEN		1
# define COLORSET_RED		2

#endif
