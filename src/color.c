/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:22:27 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/16 16:56:11 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_rgb	int_to_rgb(int c)
{
	t_rgb	r;

	r.r = (c & 0xff0000) >> 16;
	r.g = (c & 0xff00) >> 8;
	r.b = c & 0xff;
	return (r);
}

int		add_colors(int cl1, int cl2)
{
	t_rgb	c1;
	t_rgb	c2;
	t_rgb	res;

	c1 = int_to_rgb(cl1);
	c2 = int_to_rgb(cl2);
	res.r = (c1.r + c2.r >= 255) ? 255 : c1.r + c2.r;
	res.g = (c1.g + c2.g >= 255) ? 255 : c1.g + c2.g;
	res.b = (c1.b + c2.b >= 255) ? 255 : c1.b + c2.b;
	return (res.r << 16 | res.g << 8 | res.b);
}

int		mul_colors(int cl1, double k)
{
	t_rgb		res;

	res = int_to_rgb(cl1);
	res.r = (res.r * k >= 255) ? 255 : res.r * k;
	res.g = (res.g * k >= 255) ? 255 : res.g * k;
	res.b = (res.b * k >= 255) ? 255 : res.b * k;
	return (res.r << 16 | res.g << 8 | res.b);
}

int		shade_colors(int cl1, double k)
{
	t_rgb		res;

	res = int_to_rgb(cl1);
	res.r *= 1 - k;
	res.g *= 1 - k;
	res.b *= 1 - k;
	res.r = (res.r < 0) ? 0 : res.r;
	res.r = (res.r > 255) ? 255 : res.r;
	res.g = (res.g < 0) ? 0 : res.g;
	res.g = (res.g > 255) ? 255 : res.g;
	res.b = (res.b < 0) ? 0 : res.b;
	res.b = (res.b > 255) ? 255 : res.b;
	return (res.r << 16 | res.g << 8 | res.b);
}
