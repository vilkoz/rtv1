/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:17:44 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/15 19:01:55 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int argc, char **argv)
{
	t_e		*e;

	(void)argv;
	(void)argc;
	e = ft_mlx_init();
	example(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_mlx_events(e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
