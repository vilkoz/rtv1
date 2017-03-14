/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:16:59 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/14 17:36:24 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
