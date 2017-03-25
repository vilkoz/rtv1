/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:16:50 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 17:17:07 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		new_color(t_rgb res)
{
	res.r = (res.r < 0) ? 0 : res.r;
	res.r = (res.r > 255) ? 255 : res.r;
	res.g = (res.g < 0) ? 0 : res.g;
	res.g = (res.g > 255) ? 255 : res.g;
	res.b = (res.b < 0) ? 0 : res.b;
	res.b = (res.b > 255) ? 255 : res.b;
	return (res.r << 16 | res.g << 8 | res.b);
}
