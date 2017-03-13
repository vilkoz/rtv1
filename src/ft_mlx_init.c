/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:25:07 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/13 18:59:52 by vrybalko         ###   ########.fr       */
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
	return (e);
}
