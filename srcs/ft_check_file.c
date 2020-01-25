/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:52:30 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/23 06:13:18 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_isallnumber(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_game_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->map_col)
	{
		if (map->map[0][i] != '1' || map->map[map->map_row - 1][i] != '1')
			return (-1);
	}
	i = -1;
	while (++i < map->map_row)
		if (map->map[i][0] != '1' || map->map[i][map->map_col - 1] != '1')
			return (-1);
	return (1);
}

void		cheack_sprite(t_game *game)
{
	if (game->tex[TEX_NO].path == NULL)
		log_global_error("north texture not specifed", game);
	if (game->tex[TEX_SO].path == NULL)
		log_global_error("SOUTH texture not specifed", game);
	if (game->tex[TEX_WE].path == NULL)
		log_global_error("WESTE texture not specifed", game);
	if (game->tex[TEX_EA].path == NULL)
		log_global_error("EASTE texture not specifed", game);
	if (game->tex[TEX_S].path == NULL)
		log_global_error("SPRITE texture not specifed", game);
}

void		check_game(t_game *game, t_map *map)
{
	if (game->res_x > DEFAULT_WINDOW_X || game->res_y > DEFAULT_WINDOW_Y)
	{
		game->res_x = DEFAULT_WINDOW_X;
		game->res_y = DEFAULT_WINDOW_Y;
	}
	cheack_sprite(game);
	if (game->res_x < 100 || game->res_y < 100)
		log_global_error("Resolution is to small", game);
	if (game->f < 0)
		log_global_error("Unvalid floor color", game);
	if (game->c < 0)
		log_global_error("Unvalid ceiling color", game);
	if (map->player_x == -1 || map->player_y == -1)
		log_global_error("Unvalid player position on map", game);
	if ((map->map_row < 3 || map->map_col < 3))
		log_global_error("Map is to small", game);
	if (check_game_map(map) < 0)
		log_global_error("The map is not close", game);
}
