/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:29:47 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 18:47:07 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MATH_H
# define MY_MATH_H

# include "fractol.h"

typedef struct s_complex_number
{
	int	re;
	int im;
}	t_complex_number;

t_complex_number	sum(t_complex_number a, t_complex_number b);
t_complex_number	multiply(t_complex_number a, t_complex_number b);
void				mandelbrot(t_win *vars);

#endif