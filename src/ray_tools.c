/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:16:59 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 17:10:42 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		v_len(t_v3d v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double		distance(t_p3d p1, t_p3d p2)
{
	return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) +
				(p1.z - p2.z) * (p1.z - p2.z)));
}

t_v3d		normalize(t_v3d v)
{
	double		len;

	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (len == 0)
		len = 1;
	return (new_v3d(v.x / len, v.y / len, v.z / len));
}

t_v3d		new_v3d(double x, double y, double z)
{
	t_v3d	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_v3d		new_v3d_p(t_p3d p1, t_p3d p2)
{
	t_v3d	v;

	v.x = p1.x - p2.x;
	v.y = p1.y - p2.y;
	v.z = p1.z - p2.z;
	return (v);
}
