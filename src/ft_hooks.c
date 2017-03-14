/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:13:21 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/15 00:32:13 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_press(int key, t_e *e)
{
	(void)key;
	(void)e;
	return (0);
}

int		key_release(int key, t_e *e)
{
	if (key == 53)
		exit(0);
	(void)e;
	return (0);
}

int		loop_hook(t_e *e)
{
	(void)e;
	//mlx_destroy_image(e->mlx, e->img);
	//e->img = mlx_new_image(e->mlx, e->w, e->h);
	//mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
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
