/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:21:29 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/27 20:14:25 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_complex	create_complex_number(void)
{
	t_complex	num;

	num.re = 0;
	num.im = 0;
	return (num);
}

t_complex	init_complex(double re, double im)
{
	t_complex	result;

	result.re = re;
	result.im = im;
	return (result);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result = create_complex_number();
	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex	multiply_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result = create_complex_number();
	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}
