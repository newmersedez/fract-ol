/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:21:29 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 18:53:50 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_complex_number	create_complex_number(void)
{
	t_complex_number	num;

	num.re = 0;
	num.im = 0;
	return (num);
}

t_complex_number	sum(t_complex_number a, t_complex_number b)
{
	t_complex_number	result;

	result = create_complex_number();
	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex_number	multiply(t_complex_number a, t_complex_number b)
{
	t_complex_number	result;

	result = create_complex_number();
	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}
