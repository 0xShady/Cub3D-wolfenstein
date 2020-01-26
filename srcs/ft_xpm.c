/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 23:57:32 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/26 18:24:04 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		life_bar(t_game *game)
{
	int i;
	int j;
	int x;
	int y;
	int color;

	i = game->res_y - (game->res_y / 8);
	x = 0;
	y = 0;
	while (i < game->res_y)
	{
		j = 0 + (game->res_x / 24);
		y = 0;
		while (j < game->res_x)
		{
			color = game->tex[TEX_LIFE].tex[y][x];
			if (color)
				game->img.data[game->res_x * i + j] =
				game->tex[TEX_LIFE].tex[y][x];
			j++;
			y++;
		}
		i++;
		x++;
	}
}

void		ft_scoop(t_game *game)
{
	int i;
	int j;
	int x;
	int y;
	int color;

	i = game->res_y - (game->res_y / 2);
	x = 0;
	y = 0;
	while (i < game->res_y)
	{
		j = 0 + (game->res_x / 2);
		y = 0;
		while (j < game->res_x)
		{
			color = game->tex[TEX_SCOOP].tex[y][x];
			if (color)
				game->img.data[game->res_x * i + j] =
				game->tex[TEX_SCOOP].tex[y][x];
			j++;
			y++;
		}
		i++;
		x++;
	}
}
