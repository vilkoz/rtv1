/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:36:47 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/17 21:19:15 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			is_viewable(t_p3d p1, t_p3d p2, t_scene *s)
{
	int		i;
	t_o3d	*obj;
	t_v3d	norm;
	t_p3d	inter_p;
	t_p3d	p_b;

	i = -1;
	while (++i < s->obj_num)
	{
		obj = s->objects[i];
		norm = obj->get_norm(obj->data, p1);
		p_b = new_p3d(p1.x + norm.x * s->bias, p1.y + norm.y * s->bias,
			p1.z + norm.z * s->bias);
		if (obj->intersect(obj->data, p_b, normalize(
			new_v3d(p2.x - p_b.x, p2.y - p_b.y, p2.z - p_b.z)), &inter_p))
			return (FALSE);
	}
	return (TRUE);
}

int			get_light_color(t_scene *s, t_v3d norm, t_p3d inter_p, int c)
{
	t_v3d		v_ls;
	int			light_c;

	if (is_viewable(inter_p, s->ls, s))
	{
		v_ls = normalize(new_v3d(s->ls.x - inter_p.x, s->ls.y - inter_p.y,
			s->ls.z - inter_p.z));
		light_c = add_colors(c, mul_colors(0xffffff,
			fabs(cos_vectors(norm, v_ls))));
	}
	else
	{
		v_ls = normalize(new_v3d(inter_p.x - s->ls.x, inter_p.y - s->ls.y,
			inter_p.z - s->ls.z));
		light_c = shade_colors(c,
			fabs(cos_vectors(norm, v_ls)));
	}
	return (light_c);
}

/*
** p.x = min
** p.y = dist
*/

int			find_nearest(t_scene *s, t_v3d dir, t_p3d *inter_p, t_o3d **obj1)
{
	t_o3d	*obj;
	int		i;
	t_p2d	p;
	t_p3d	min_p;

	i = -1;
	p.x = 0;
	while (++i < s->obj_num)
	{
		obj = s->objects[i];
		if (obj->intersect(obj->data, s->cam.pos, dir, inter_p))
		{
			p.y = distance(*inter_p, s->cam.pos);
			(p.x == 0) ? p.x = p.y : 23;
			if (p.y <= p.x)
			{
				p.x = p.y;
				min_p = new_p3d(inter_p->x, inter_p->y, inter_p->z);
				*obj1 = obj;
			}
		}
	}
	*inter_p = (p.x != 0) ? new_p3d(min_p.x, min_p.y, min_p.z) : *inter_p;
	if (p.x == 0)
		return (FALSE);
	else
		return (TRUE);
}

void		find_intersect(t_e *e, t_scene *s)
{
	t_p2d		p;
	t_p2d		p1;
	t_v3d		dir;
	t_p3d		inter_p;
	t_o3d		*obj;

	p1.y = -1;
	while (++p1.y < e->h)
	{
		p1.x = -1;
		while (++p1.x < e->w)
		{
			p.x = (p1.x - e->w / 2.0);
			p.y = (p1.y - e->h / 2.0);
			dir = new_v3d(p.x, p.y, 400);
			dir = rotate_v_x(dir, s->cam.sin.x, s->cam.cos.x);
			dir = rotate_v_z(dir, s->cam.sin.z, s->cam.cos.z);
			dir = rotate_v_y(dir, s->cam.sin.y, s->cam.cos.y);
			if (find_nearest(s, normalize(dir), &inter_p, &obj))
				ft_img_px_put(e, p1.x, p1.y, get_light_color(s,
					obj->get_norm(obj->data, inter_p), inter_p,
					obj->get_color(obj->data, inter_p)));
		}
	}
}

void		example(t_e *e)
{
	t_o3d		*obj[5];
	t_v3d		ray;
	t_scene		*s;

	obj[0] = new_sphere(new_p3d(30, 0, 30), 10, 0xff0000);
	obj[1] = new_sphere(new_p3d(-30, 0, -30), 10, 0xff00);
	obj[2] = new_sphere(new_p3d(30, 0, -30), 10, 0xffa0);
	obj[3] = new_sphere(new_p3d(-30, 0, 30), 10, 0xffb0);
	obj[4] = new_plane(new_p3d(-30, 0, 0), new_v3d(-1, 0, 0), 0xff0000);
	ray = new_v3d(0, -1, 0);
	ray = rotate_v_x(ray, sin(e->ang_x * RAD), cos(e->ang_x * RAD));
	ray = rotate_v_y(ray, sin(e->ang_y * RAD), cos(e->ang_y * RAD));
	ray = rotate_v_z(ray, sin(70 * RAD), cos(70 * RAD));
	printf("ray = %f %f %f\n", ray.x, ray.y, ray.z);
	s = new_scene(5, obj, new_p3d(1000, 1000, 1000),
		new_cam(new_p3d(0, 500, 0), ray));
	s->bias = e->bias;
	find_intersect(e, s);
}
