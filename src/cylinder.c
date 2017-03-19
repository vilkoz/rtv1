/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:28:14 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/19 16:28:00 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_v3d	get_norm_cyl(void *dat, t_p3d inter_p)
{
	t_cyl	*sp;
	t_p3d	c_cen;
	t_v3d	res;

	sp = (t_cyl *)dat;
	c_cen = new_p3d(sp->center.x, sp->center.y, inter_p.z);
	res = new_v3d(inter_p.x - c_cen.x, inter_p.y - c_cen.y,
		inter_p.z - c_cen.z);
	return (normalize(res));
}

int		get_cyl_color(void *data, t_p3d inter_p)
{
	(void)inter_p;
	return (((t_cyl *)data)->color);
}

int		intersect_cyl(const void *data, const t_p3d ray_start,
						const t_v3d ray, t_p3d *inter_p)
{
	double		t0;
	double		t1;
	t_cyl		*sp;

	sp = (t_cyl *)data;
	if (!solve_quad(new_p3d(ray.x * ray.x + ray.y * ray.y, 2. * (ray.x *
		(ray_start.x - sp->center.x) + ray.y * (ray_start.y - sp->center.y)),
		(ray_start.x - sp->center.x) * (ray_start.x - sp->center.x) +
		(ray_start.y - sp->center.y) * (ray_start.y - sp->center.y) -
		pow(sp->radius, 2)), &t0, &t1))
		return (FALSE);
	if (t0 > t1)
		SWAP_D(t0, t1);
	if ((t0 < 0) && ((t0 = t1) < 0))
		return (FALSE);
	*inter_p = new_p3d(ray_start.x + t0 * ray.x, ray_start.y + t0 * ray.y,
					ray_start.z + t0 * ray.z);
	if (fabs(inter_p->z - sp->center.z) > fabs(sp->h))
	{
		*inter_p = new_p3d(ray_start.x + t1 * ray.x, ray_start.y + t1 * ray.y,
						ray_start.z + t1 * ray.z);
		if (fabs(inter_p->z - sp->center.z) > fabs(sp->h))
			return (FALSE);
	}
	return (TRUE);
}

t_o3d	*new_cyl(t_p3d center, double radius, double h, int color)
{
	t_cyl		*sp;
	t_o3d		*obj;

	sp = (t_cyl *)malloc(sizeof(t_cyl));
	sp->center = center;
	sp->radius = radius;
	sp->color = color;
	sp->h = h;
	obj = (t_o3d *)malloc(sizeof(t_o3d));
	obj->data = (void *)sp;
	obj->get_color = get_cyl_color;
	obj->intersect = intersect_cyl;
	obj->get_norm = get_norm_cyl;
	return (obj);
}
