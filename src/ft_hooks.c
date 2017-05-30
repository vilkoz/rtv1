/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:13:21 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 16:33:50 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_press(int key, t_e *e)
{
	if (key == 53)
		exit(0);
	(void)e;
	return (0);
}

int		key_release(int key, t_e *e)
{
	if (key == 53)
		exit(0);
	if (key == 36)
	{
		mlx_loop_hook(e->mlx, loop_hook, e);
		e->changed = 2;
	}
	(void)e;
	return (0);
}

int		loop_hook(t_e *e)
{
	if (e->changed == 0)
		return (0);
	else if (e->changed == 2)
	{
		mlx_clear_window(e->mlx, e->win);
		put_loading(e);
		e->changed = 1;
		return (0);
	}
	render(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	e->changed = 0;
	mlx_loop_hook(e->mlx, NULL, NULL);
	return (0);
}

int		mouse_hook(int key, int x, int y, t_e *e)
{
	e->v_y = y;
	e->v_x = x;
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
