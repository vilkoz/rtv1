/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:23:08 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 17:26:03 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		read_sphere(t_scene *s, char **arr)
{
	int			i;
	t_sphere	sp;

	i = 0;
	sp.center.x = 0;
	sp.center.y = 0;
	sp.center.z = 0;
	sp.radius = 10;
	sp.color = 0xff50ff;
	while (arr[++i] != NULL)
	{
		(i == 1) ? sp.center.x = ft_atoi(arr[i]) : 23;
		(i == 2) ? sp.center.y = ft_atoi(arr[i]) : 23;
		(i == 3) ? sp.center.z = ft_atoi(arr[i]) : 23;
		(i == 4) ? sp.radius = (double)ft_atoi(arr[i]) : 23;
		if (i == 5 && ft_strchr(arr[i], 'x') != NULL)
			sp.color = ft_atoi_base(ft_strchr(arr[i], 'x') + 1, 16);
	}
	s->objects[s->cur_o] = new_sphere(new_p3d(sp.center.x, sp.center.y,
		sp.center.z), sp.radius, sp.color);
	s->cur_o++;
	free_arr(&arr);
}

void		read_light(t_scene *s, char **arr)
{
	t_p3d	p;
	int		i;

	p.x = 1000;
	p.y = 1000;
	p.z = 1000;
	i = 0;
	while (arr[++i] != NULL)
	{
		(i == 1) ? p.x = ft_atoi(arr[i]) : 23;
		(i == 2) ? p.y = ft_atoi(arr[i]) : 23;
		(i == 3) ? p.z = ft_atoi(arr[i]) : 23;
	}
	s->ls[s->cur_ls] = (t_p3d *)malloc(sizeof(t_p3d));
	*s->ls[s->cur_ls] = new_p3d(p.x, p.y, p.z);
	s->cur_ls++;
	free_arr(&arr);
}

void		read_plane(t_scene *s, char **arr)
{
	t_plane		p;
	int			i;

	p.p.x = 0;
	p.p.y = 1;
	p.p.z = 2;
	p.norm = new_v3d(0, 1, 0);
	p.color = 0xff50ff;
	i = 0;
	while (arr[++i] != NULL)
	{
		(i == 1) ? p.p.x = ft_atoi(arr[i]) : 23;
		(i == 2) ? p.p.y = ft_atoi(arr[i]) : 23;
		(i == 3) ? p.p.z = ft_atoi(arr[i]) : 23;
		(i == 4) ? p.norm.x = ft_atoi(arr[i]) : 23;
		(i == 5) ? p.norm.y = ft_atoi(arr[i]) : 23;
		(i == 6) ? p.norm.z = ft_atoi(arr[i]) : 23;
		if (i == 7 && ft_strchr(arr[i], 'x') != NULL)
			p.color = ft_atoi_base(ft_strchr(arr[i], 'x') + 1, 16);
	}
	p.norm = (!p.norm.x && !p.norm.y && !p.norm.z) ? new_v3d(0, 1, 0) : p.norm;
	s->objects[s->cur_o] = new_plane(new_p3d(p.p.x, p.p.y, p.p.z),
		new_v3d(p.norm.x, p.norm.y, p.norm.z), p.color);
	s->cur_o++;
	free_arr(&arr);
}

void		read_cam(t_scene *s, char **arr)
{
	t_cam	cam;
	int		i;

	i = -1;
	cam.pos.x = 100;
	cam.pos.y = 100;
	cam.pos.x = 100;
	cam.dir.x = 0;
	cam.dir.y = -1;
	cam.dir.z = 0;
	while (arr[++i] != NULL)
	{
		(i == 1) ? cam.pos.x = ft_atoi(arr[i]) : 23;
		(i == 2) ? cam.pos.y = ft_atoi(arr[i]) : 24;
		(i == 3) ? cam.pos.z = ft_atoi(arr[i]) : 23;
		(i == 4) ? cam.dir.x = ft_atoi(arr[i]) : 23;
		(i == 5) ? cam.dir.y = ft_atoi(arr[i]) : 23;
		(i == 6) ? cam.dir.z = ft_atoi(arr[i]) : 23;
	}
	cam.dir = (!cam.dir.x && !cam.dir.y && !cam.dir.z) ? new_v3d(0, 1, 0) :
		cam.dir;
	s->cam = new_cam(new_p3d(cam.pos.x, cam.pos.y, cam.pos.z),
		new_v3d(cam.dir.x, cam.dir.y, cam.dir.z));
	free_arr(&arr);
}
