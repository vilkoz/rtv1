/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:17:44 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/15 00:55:44 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		find_intersect(t_e *e, t_o3d *obj, t_p3d camera, t_v3d ray)
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
			p.x = x - e->w / 2.0;
			p.y = y - e->h / 2.0;
			dir = normalize(new_v3d(p.x, p.y, 1));
			//printf("1dir.x = %f, dir.y = %f, dir.z = %f\n", dir.x, dir.y, dir.z);
			dir = rotate_v_x(dir, sin(ray.x), cos(ray.x));
			dir = rotate_v_z(dir, sin(ray.z), cos(ray.z));
			dir = rotate_v_y(dir, sin(ray.y), cos(ray.y));
			//printf("2dir.x = %f, dir.y = %f, dir.z = %f\n", dir.x, dir.y, dir.z);
			if (obj->intersect(obj->data, camera, dir, &inter_p))
				ft_img_px_put(e, x, y, obj->get_color(obj->data, inter_p));
		}
	}
}

void		example(t_e *e)
{
	t_o3d		*obj[2];
	t_p3d		camera;
	t_v3d		ray;
	int			i;

	obj[0] = new_sphere(new_p3d(10, 20, 30), 100, 0xff0000);
	obj[1] = new_sphere(new_p3d(0, 0, 0), 10, 0xff00);
	ray = new_v3d(0, -1, 0);
	camera = new_p3d(0, 100, 0);
	i = -1;
	while (++i < 1)
		find_intersect(e, obj[i], camera, ray);
}

int			main(int argc, char **argv)
{
	t_e		*e;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr("usage ./wolf3D <map_file>\n");
		return (1);
	}
	e = ft_mlx_init();
	example(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_mlx_events(e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
