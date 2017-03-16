/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:13:21 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/16 17:18:03 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_press(int key, t_e *e)
{
	(key == 123) ? e->k.rot_x = -1 : 23;
	(key == 124) ? e->k.rot_x = 1 : 23;
	(key == 125) ? e->k.rot_y = -1 : 23;
	(key == 126) ? e->k.rot_y = 1 : 23;
	(key == 24) ? e->k.bias = 1 : 23;
	(key == 27) ? e->k.bias = -1 : 23;
	return (0);
}

int		key_release(int key, t_e *e)
{
	if (key == 53)
		exit(0);
	(key == 123 || key == 124) ? e->k.rot_x = 0 : 23;
	(key == 125 || key == 126) ? e->k.rot_y = 0 : 23;
	(key == 24 || key == 27) ? e->k.bias = 0 : 23;
	return (0);
}

int		loop_hook(t_e *e)
{
	(e->k.rot_x == 1) ? e->ang_x += 1 : 23;
	(e->k.rot_x == -1) ? e->ang_x -= 1 : 23;
	(e->k.rot_y == 1) ? e->ang_y += 1 : 23;
	(e->k.rot_y == -1) ? e->ang_y -= 1 : 23;
	(e->k.bias == -1) ? e->bias -= 0.1 : 23;
	(e->k.bias == 1) ? e->bias += 0.1 : 23;
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->w, e->h);
	example(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		mouse_hook(int key, int x, int y, t_e *e)
{
	(void)y;
	(void)x;
	(void)e;
	(void)key;
	return (0);
}

int		move_hook(int x, int y, t_e *e)
{
	(void)y;
	(void)x;
	(void)e;
	return (0);
}
