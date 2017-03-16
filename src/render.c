/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:36:47 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/16 23:31:23 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			is_viewable(t_p3d p1, t_p3d p2, t_scene *s)
{
	t_o3d	*obj;
	t_p3d	inter_p;
	t_p3d	p_b;
	t_v3d	norm;

	if (find_nearest(s, normalize(
		new_v3d(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z)), &inter_p, &obj, p1))
	{
		norm = obj->get_norm(obj->data, inter_p);
		p_b = new_p3d(p1.x + norm.x * s->bias, p1.y + norm.y * s->bias,
			p1.z + norm.z * s->bias);
		if (find_nearest(s, normalize(new_v3d(p2.x - p_b.x, p2.y - p_b.y,
							p2.z - p_b.z)), &inter_p, &obj, p_b))
			return (FALSE);
		else
			return (TRUE);
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

int			find_nearest(t_scene *s, t_v3d dir, t_p3d *inter_p, t_o3d **obj1,
				t_p3d s_point)
{
	t_o3d	*obj;
	int		i;
	double	min;
	double	dist;
	t_p3d	min_p;

	i = -1;
	min = 0;
	while (++i < s->obj_num)
	{
		obj = s->objects[i];
		if (obj->intersect(obj->data, s_point, dir, inter_p))
		{
			dist = distance(*inter_p, s_point);
			(min == 0) ? min = dist : 23;
			if (dist <= min)
			{
				min = dist;
				min_p = new_p3d(inter_p->x, inter_p->y, inter_p->z);
				*obj1 = obj;
			}
		}
	}
	if (min == 0)
		return (FALSE);
	else
	{
		*inter_p = new_p3d(min_p.x, min_p.y, min_p.z);
		return (TRUE);
	}
}

void		find_intersect(t_e *e, t_scene *s)
{
	int			x;
	int			y;
	t_p2d		p;
	t_v3d		dir;
	t_p3d		inter_p;
	t_o3d		*obj;

	y = -1;
	while (++y < e->h)
	{
		x = -1;
		while (++x < e->w)
		{
			p.x = (x - e->w / 2.0);
			p.y = (y - e->h / 2.0);
			dir = new_v3d(p.x, p.y, 400);
			dir = rotate_v_x(dir, s->cam.sin.x, s->cam.cos.x);
			dir = rotate_v_z(dir, s->cam.sin.z, s->cam.cos.z);
			dir = rotate_v_y(dir, s->cam.sin.y, s->cam.cos.y);
			if (find_nearest(s, normalize(dir), &inter_p, &obj, s->cam.pos))
				ft_img_px_put(e, x, y, get_light_color(s,
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
	obj[4] = new_sphere(new_p3d(0, -10050, 0), 10000, 0xffa500);
	ray = new_v3d(0, -1, 0);
	ray = rotate_v_x(ray, sin(e->ang_x * RAD), cos(e->ang_x * RAD));
	ray = rotate_v_y(ray, sin(e->ang_y * RAD), cos(e->ang_y * RAD));
	ray = rotate_v_z(ray, sin(70 * RAD), cos(70 * RAD));
	printf("ray = %f %f %f\n", ray.x, ray.y, ray.z);
	s = new_scene(5, obj, new_p3d(300, 200, 30),
		new_cam(new_p3d(0, 200, 0), ray));
	s->bias = e->bias;
	find_intersect(e, s);
}
