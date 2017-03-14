/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:17:44 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/14 20:00:35 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		find_intersect(t_e *e, t_o3d *obj, t_p3d camera, t_v3d ray)
{
	int			x;
	int			y;
	t_p2d		p;
	t_p3d		inter_p;
	t_v3d		perp;

	perp = new_v3d(1, 1, -(ray.x + ray.y) / ray.z);
	y = -1;
	while (++y < e->h)
	{
		x = -1;
		while (++x < e->w)
		{
			p.x = 2 * x / (double)e->w - 1;
			p.y = 2 * y / (double)e->h - 1;
			if (obj->intersect(obj->data, camera, ray, &inter_p))
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
	camera = new_p3d(0, 0, -100);
	i = -1;
	while (++i < 2)
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
