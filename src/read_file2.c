/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:24:40 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 17:27:36 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_cyl(t_cyl *c)
{
	c->center.x = 0;
	c->center.y = 0;
	c->center.z = 0;
	c->dir.x = 0;
	c->dir.y = 0;
	c->dir.z = 1;
	c->radius = 100;
	c->h = 10000;
	c->color = 0xffa0;
}

void		read_cyl(t_scene *s, char **arr)
{
	t_cyl	c;
	int		i;

	i = 0;
	init_cyl(&c);
	while (arr[++i])
	{
		(i == 1) ? c.center.x = ft_atoi(arr[i]) : 23;
		(i == 2) ? c.center.y = ft_atoi(arr[i]) : 23;
		(i == 3) ? c.center.z = ft_atoi(arr[i]) : 23;
		(i == 4) ? c.dir.x = ft_atoi(arr[i]) : 23;
		(i == 5) ? c.dir.y = ft_atoi(arr[i]) : 23;
		(i == 6) ? c.dir.z = ft_atoi(arr[i]) : 23;
		(i == 7) ? c.radius = (double)ft_atoi(arr[i]) : 23;
		(i == 8) ? c.h = (double)ft_atoi(arr[i]) : 23;
		if (i == 9 && ft_strchr(arr[i], 'x') != NULL)
			c.color = ft_atoi_base(ft_strchr(arr[i], 'x') + 1, 16);
	}
	c.dir = (!c.dir.x && !c.dir.y && !c.dir.z) ? new_v3d(0, 1, 0) :
		c.dir;
	s->objects[s->cur_o] = new_cyl(new_vec(new_v3d(c.dir.x, c.dir.y, c.dir.z),
		new_p3d(c.center.x, c.center.y, c.center.z)), c.radius, c.h, c.color);
	s->cur_o++;
	free_arr(&arr);
}

void		init_cone(t_cone *c)
{
	c->center.x = 0;
	c->center.y = 0;
	c->center.z = 0;
	c->dir.x = 0;
	c->dir.y = 0;
	c->dir.z = 1;
	c->a = 60;
	c->h = 10000;
	c->color = 0xffa0;
}

void		read_cone(t_scene *s, char **arr)
{
	t_cone	c;
	int		i;

	i = 0;
	init_cone(&c);
	while (arr[++i])
	{
		(i == 1) ? c.center.x = ft_atoi(arr[i]) : 23;
		(i == 2) ? c.center.y = ft_atoi(arr[i]) : 23;
		(i == 3) ? c.center.z = ft_atoi(arr[i]) : 23;
		(i == 4) ? c.dir.x = ft_atoi(arr[i]) : 23;
		(i == 5) ? c.dir.y = ft_atoi(arr[i]) : 23;
		(i == 6) ? c.dir.z = ft_atoi(arr[i]) : 23;
		(i == 7) ? c.a = (double)ft_atoi(arr[i]) : 23;
		(i == 8) ? c.h = (double)ft_atoi(arr[i]) : 23;
		if (i == 9 && ft_strchr(arr[i], 'x') != NULL)
			c.color = ft_atoi_base(ft_strchr(arr[i], 'x') + 1, 16);
	}
	c.dir = (!c.dir.x && !c.dir.y && !c.dir.z) ? new_v3d(0, 1, 0) :
		c.dir;
	s->objects[s->cur_o] = new_cone(new_vec(normalize(new_v3d(c.dir.x, c.dir.y,
		c.dir.z)), new_p3d(c.center.x, c.center.y, c.center.z)), c.h, c.color,
		c.a);
	s->cur_o++;
	free_arr(&arr);
}

void		read_lines(t_scene *s, t_list *lst)
{
	t_list		*tmp;
	char		*l;

	tmp = lst;
	s->objects = (t_o3d **)malloc(sizeof(t_o3d *) * s->obj_num);
	s->ls = (t_p3d **)malloc(sizeof(t_p3d *) * s->ls_num);
	while (tmp)
	{
		l = (char *)tmp->content;
		if (l[0] == 'l')
			read_light(s, ft_strsplit(l, ' '));
		if (l[0] == 's')
			read_sphere(s, ft_strsplit(l, ' '));
		if (l[0] == 'p')
			read_plane(s, ft_strsplit(l, ' '));
		if (l[0] == 'y')
			read_cyl(s, ft_strsplit(l, ' '));
		if (l[0] == 'o')
			read_cone(s, ft_strsplit(l, ' '));
		if (l[0] == 'c')
			read_cam(s, ft_strsplit(l, ' '));
		tmp = tmp->next;
	}
}
