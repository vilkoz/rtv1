/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:12:32 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/20 11:35:23 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_v3d	get_norm_cone(void *dat, t_p3d inter_p)
{
	t_cone	*sp;
	t_p3d	c_cen;
	t_v3d	o;
	t_v3d	res;

	sp = (t_cone *)dat;
	o = normalize(new_v3d_p(inter_p, sp->center));
	c_cen = new_p3d(sp->center.x, sp->center.y, inter_p.z);
	res = normalize(new_v3d_p(inter_p, c_cen));
	if (inter_p.z < sp->center.z)
		res = new_v3d(res.x - o.x, res.y - o.y, res.z - o.z);
	else
		res = new_v3d(o.x - res.x, o.y - res.y, o.z - res.z);
	return (normalize(res));
}

int		get_cone_color(void *data, t_p3d inter_p)
{
	(void)inter_p;
	return (((t_cone *)data)->color);
}

int		solve_quad_rot(const void *data, t_vec v, double *t0, double *t1)
{
	t_cone		*sp;
	t_v3d		ray;
	t_p3d		ray_start;

	sp = (t_cone *)data;
	ray = v.dir;
	ray_start = v.p;
	if (!solve_quad(new_p3d(ray.x * ray.x / A2 + ray.y * ray.y / B2 -
							ray.z * ray.z / C2,
		2. * (ray.x * (ray_start.x - sp->center.x) / A2 +
			ray.y * (ray_start.y - sp->center.y) / B2 -
			ray.z * (ray_start.z - sp->center.z) / C2),
		(ray_start.x - sp->center.x) * (ray_start.x - sp->center.x) / A2 +
		(ray_start.y - sp->center.y) * (ray_start.y - sp->center.y) / B2 -
		(ray_start.z - sp->center.z) * (ray_start.z - sp->center.z) / C2),
		t0, t1))
		return (FALSE);
	return (TRUE);
}

int		intersect_cone(const void *data, const t_p3d ray_start,
						const t_v3d ray, t_p3d *inter_p)
{
	double		t0;
	double		t1;
	t_cone		*sp;

	sp = (t_cone *)data;
	if (!solve_quad_rot(data, new_vec(ray, ray_start), &t0, &t1))
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

t_o3d	*new_cone(t_vec v, double h, int color)
{
	t_cone		*sp;
	t_o3d		*obj;

	sp = (t_cone *)malloc(sizeof(t_cone));
	sp->center = v.p;
	sp->dir = v.dir;
	sp->color = color;
	sp->h = h;
	obj = (t_o3d *)malloc(sizeof(t_o3d));
	obj->data = (void *)sp;
	obj->get_color = get_cone_color;
	obj->intersect = intersect_cone;
	obj->get_norm = get_norm_cone;
	return (obj);
}
