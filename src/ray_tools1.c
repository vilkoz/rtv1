/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:01:12 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 17:02:16 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			same_dir(t_v3d v1, t_v3d v2)
{
	if (acos(dot_product(normalize(v1), normalize(v2))) / RAD > 90)
		return (FALSE);
	else
		return (TRUE);
}

t_v3d		v_inv(t_v3d v)
{
	return (v_sub(new_v3d(0, 0, 0), v));
}

double		v_sqr(t_v3d v)
{
	return (dot_product(v, v));
}

t_v3d		v_add(t_v3d v1, t_v3d v2)
{
	t_v3d		res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_v3d		v_sub(t_v3d v1, t_v3d v2)
{
	t_v3d		res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}
