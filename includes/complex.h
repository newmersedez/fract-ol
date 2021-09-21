/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:29:47 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 21:34:13 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include "fractol.h"

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

t_complex	init_complex(double re, double im);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	multiply_complex(t_complex a, t_complex b);

#endif