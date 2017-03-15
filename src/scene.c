/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:27:17 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/15 16:50:42 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam		new_cam(t_p3d pos, t_v3d dir)
{
	t_cam		cam;

	cam.pos = pos;
	cam.dir = dir;
	return (cam);
}

t_scene		*new_scene(int obj_num, t_o3d **obj, t_p3d ls, t_cam cam)
{
	t_scene		*new;

	new = (t_scene *)malloc(sizeof(t_scene));
	new->obj_num = obj_num;
	new->objects = obj;
	new->ls = ls;
	new->cam = cam;
	return (new);
}
