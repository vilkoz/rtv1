/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:02:39 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 17:10:05 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_p3d		new_p3d(double x, double y, double z)
{
	t_p3d	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec		new_vec(t_v3d v, t_p3d p)
{
	t_vec	new;

	new.dir = v;
	new.p = p;
	return (new);
}

double		dot_product(t_v3d v1, t_v3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_v3d		cross_product(t_v3d a, t_v3d b)
{
	t_v3d		res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

t_v3d		v_mul(t_v3d v, double n)
{
	v.x *= n;
	v.y *= n;
	v.z *= n;
	return (v);
}
