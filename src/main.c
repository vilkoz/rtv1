/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:17:44 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 16:25:57 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		put_loading(t_e *e)
{
	char		*s;

	s = ft_strdup("loading...");
	mlx_string_put(e->mlx, e->win, 500, 500, 0xffffff, s);
	free(s);
}

int			main(int argc, char **argv)
{
	t_e		*e;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./RTv1 scene_file\n", 2);
		exit(1);
	}
	e = ft_mlx_init(read_file(argv[1]));
	ft_mlx_events(e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
