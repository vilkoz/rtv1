/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:05:49 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/13 20:40:32 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_sphere_color(void *data, t_p3d inter_p)
{
	(void)inter_p;
	return (((t_sphere *)data)->color);
}

int		intersect_sphere(const void *data, const t_p3d ray_start,
						const t_v3d ray, t_p3d *inter_p)
{
	double	a;
	double	b;
	double	c;
	t_sphere	*sp;

	sp = (t_sphere *)data;
	a = 1;
	b = 2 * (ray.x * (ray_start.x - sp->center.x) +
			ray.y * (ray_start.y - sp->center.y) +
			ray.z * (ray_start.z - sp->center.z));

	// TODO: this shit
	c =
}

t_o3d	*new_sphere(t_p3d center, double radius, int color)
{
	t_sphere	*sp;
	t_o3d		*obj;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	sp->center = center;
	sp->radius = radius;
	sp->color = color;
	obj = (t_o3d *)malloc(sizeof(t_o3d));
	obj->data = (void *)sp;
	obj->get_color = get_sphere_color;
	return (obj);
}
