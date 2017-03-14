/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:16:59 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/15 00:39:18 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_v3d		normalize(t_v3d v)
{
	double		len;

	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (new_v3d(v.x / len, v.y / len, v.z / len));
}

t_v3d		rotate_v_x(t_v3d v, double sin_al, double cos_al)
{
	double		y;
	double		z;

	y = v.y * cos_al - v.z * sin_al;
	z = v.y * sin_al + v.z * cos_al;
	return (new_v3d(v.x, y, z));
}

t_v3d		rotate_v_y(t_v3d v, double sin_al, double cos_al)
{
	double		x;
	double		z;

	x = v.x * cos_al - v.z * sin_al;
	z = v.x * sin_al + v.z * cos_al;
	return (new_v3d(x, v.y, z));
}

t_v3d		rotate_v_z(t_v3d v, double sin_al, double cos_al)
{
	double		x;
	double		y;

	x = v.x * cos_al - v.y * sin_al;
	y = v.x * sin_al + v.y * cos_al;
	return (new_v3d(x, y, v.z));
}

t_v3d		new_v3d(double x, double y, double z)
{
	t_v3d	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_p3d		new_p3d(double x, double y, double z)
{
	t_p3d	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double		dot_product(t_v3d v1, t_v3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
