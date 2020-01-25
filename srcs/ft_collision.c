/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:52:34 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/25 18:56:52 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_sprite(t_map *map, float x, float y)
{
	int row;
	int col;

	row = floor(y / TILE_SIZE);
	col = floor(x / TILE_SIZE);
	if (map->map[row][col] == '2')
		return (1);
	return (0);
}

int		is_wall(t_map *map, float x, float y)
{
	int row;
	int col;

	row = floor(y / TILE_SIZE);
	col = floor(x / TILE_SIZE);
	if (map->map[row][col] == '1')
		return (1);
	if (map->map[row][col] == '3')
		return (2);
	return (0);
}
