/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 00:05:38 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/17 02:07:53 by vrybalko         ###   ########.fr       */
=======
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:05:49 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/17 21:26:02 by vrybalko         ###   ########.fr       */
>>>>>>> 31da62cfdae62e5a0aea3d9d0f49088edcf96021
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_v3d	get_norm_plane(void *dat, t_p3d inter_p)
{
	(void)inter_p;
	return (((t_plane *)dat)->norm);
}

int		get_plane_color(void *data, t_p3d inter_p)
{
	(void)inter_p;
	return (((t_plane *)data)->color);
}

int		intersect_plane(const void *data, const t_p3d ray_start,
						const t_v3d ray, t_p3d *inter_p)
{
	t_plane		*pl;
<<<<<<< HEAD
	double		dot;
	t_v3d		w;
	t_p3d		ray1;

	pl = (t_plane *)data;
	if (fabs(dot = dot_product(pl->norm, ray)) < EPSILON)
		return (FALSE);
	w = new_v3d(ray_start.x - pl->p.x, ray_start.y - pl->p.y,
			ray_start.z - pl->p.z);
	if ((dot = -dot_product(pl->norm, w) / dot) < 0)
		return (FALSE);
	ray1 = new_p3d(ray.x * dot, ray.y * dot, ray.z * dot);
	*inter_p = new_p3d(ray_start.x + ray1.x, ray_start.y + ray1.y,
			ray_start.z + ray1.z);
	if (dot_product(new_v3d(inter_p->x - ray_start.x, inter_p->y - ray_start.y,
			inter_p->z - ray_start.z), ray) < 0)
=======
	t_v3d		w;
	double		dot;

	pl = (t_plane *)data;
	w = new_v3d(ray_start.x - pl->p.x, ray_start.y - pl->p.y,
		ray_start.z - pl->p.z);
	if ((dot = fabs(dot_product(pl->norm, ray))) < EPSILON)
		return (FALSE);
	dot = -dot_product(pl->norm, w) / dot;
	*inter_p = new_p3d(ray_start.x + ray.x * dot, ray_start.y + ray.y * dot,
		ray_start.z + ray.z * dot);
	if (dot_product(new_v3d(inter_p->x - ray_start.x, inter_p->y - ray_start.y,
		inter_p->z - ray_start.z), ray) <= 0)
>>>>>>> 31da62cfdae62e5a0aea3d9d0f49088edcf96021
		return (FALSE);
	return (TRUE);
}

t_o3d	*new_plane(t_p3d p, t_v3d norm, int color)
{
	t_plane		*sp;
	t_o3d		*obj;

	sp = (t_plane *)malloc(sizeof(t_plane));
	sp->p = p;
	sp->norm = norm;
	sp->color = color;
	obj = (t_o3d *)malloc(sizeof(t_o3d));
	obj->data = (void *)sp;
	obj->get_color = get_plane_color;
	obj->intersect = intersect_plane;
	obj->get_norm = get_norm_plane;
	return (obj);
}
