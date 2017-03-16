/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:25:07 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/17 01:07:24 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_e			*ft_mlx_init(void)
{
	t_e		*e;

	e = (t_e *)malloc(sizeof(t_e));
	if ((e->mlx = mlx_init()) == NULL)
		return (NULL);
	e->h = 700;
	e->w = 800;
	e->win = mlx_new_window(e->mlx, e->w, e->h, "rtv1");
	e->img = mlx_new_image(e->mlx, e->w, e->h);
	e->ang_x = 17;
	e->ang_y = 90;
	e->bias = 0.001;
	return (e);
}
