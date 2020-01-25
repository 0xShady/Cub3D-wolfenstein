/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:52:49 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/23 06:13:34 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strcontaines(char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

float	norm_angle(float angle)
{
	angle = remainder(angle, M_PI * 2);
	if (angle < 0)
		angle += M_PI * 2;
	return (angle);
}

float	dist_point(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float	deg_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}

float	rad_to_deg(float rad)
{
	return (rad * (180 / M_PI));
}
