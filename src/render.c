/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:36:47 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/15 21:48:44 by vrybalko         ###   ########.fr       */
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
		norm = obj->get_norm(obj->data, inter_p);
		p_b = new_p3d(p1.x + norm.x * 0.5, p1.y + norm.y * 0.5,
			p1.z + norm.z * 0.5);
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
		light_c = 0x0;
	return (light_c);
}

void		find_intersect(t_e *e, t_o3d *obj, t_scene *s)
{
	int			x;
	int			y;
	t_p2d		p;
	t_v3d		dir;
	t_p3d		inter_p;

	y = -1;
	while (++y < e->h)
	{
		x = -1;
		while (++x < e->w)
		{
			p.x = (x - e->w / 2.0);
			p.y = (y - e->h / 2.0);
			dir = new_v3d(p.x, p.y, 300);
			dir = rotate_v_x(dir, sin(s->cam.dir.x), cos(s->cam.dir.x));
			dir = rotate_v_z(dir, sin(s->cam.dir.z), cos(s->cam.dir.z));
			dir = rotate_v_y(dir, sin(s->cam.dir.y), cos(s->cam.dir.y));
			if (obj->intersect(obj->data, s->cam.pos, normalize(dir), &inter_p))
				ft_img_px_put(e, x, y, get_light_color(s,
					obj->get_norm(obj->data, inter_p), inter_p,
					obj->get_color(obj->data, inter_p)));
		}
	}
}

void		example(t_e *e)
{
	t_o3d		*obj[2];
	t_v3d		ray;
	t_scene		*s;
	int			i;

	obj[0] = new_sphere(new_p3d(0, 10, -20), 10, 0xff0000);
	obj[1] = new_sphere(new_p3d(0, 0, 20), 10, 0xff00);
	ray = new_v3d(0, -1, 0);
	ray = rotate_v_z(ray, sin(70 * RAD), cos(70 * RAD));
	s = new_scene(2, obj, new_p3d(100, 100, 100),
		new_cam(new_p3d(0, 100, 0), ray));
	i = -1;
	while (++i < 2)
		find_intersect(e, obj[i], s);
}
