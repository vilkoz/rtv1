/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:10:25 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 17:10:39 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		cos_vectors(t_v3d v1, t_v3d v2)
{
	return (dot_product(v1, v2) /
		sqrt(sqrt(dot_product(v1, v1)) * sqrt(dot_product(v2, v2))));
}
