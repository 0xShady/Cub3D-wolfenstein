/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 05:52:38 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/26 00:05:12 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_player_on_map(t_map *map, t_player *player)
{
	player->x = map->player_x;
	player->y = map->player_y;
	player->rotate_angle = deg_to_rad(map->player_dir);
}

static void	player_acutal(t_map *map, t_player *player, float n_x, float n_y)
{
	if ((is_wall(map, n_x, n_y) == 0 || is_wall(map, n_x, n_y)
		== 2) && !is_sprite(map, n_x, n_y))
	{
		player->x = n_x;
		player->y = n_y;
	}
	else
	{
		if ((is_wall(map, player->x, n_y) == 0
			|| is_wall(map, player->x, n_y) == 2) &&
			!is_sprite(map, player->x, n_y))
			player->y = n_y;
		else if ((is_wall(map, n_x, player->y) == 0
			|| is_wall(map, n_x, player->y) == 2) &&
			!is_sprite(map, n_x, player->y))
			player->x = n_x;
	}
}

static void	player_movement_2(t_map *map, t_player *player, float walk_dir,
float straf)
{
	float	new_x;
	float	new_y;

	if (straf && walk_dir)
	{
		new_x = player->x + straf * (cos(player->rotate_angle - (M_PI / 2)));
		new_y = player->y + straf * (sin(player->rotate_angle - (M_PI / 2)));
		new_x += cos(player->rotate_angle) * walk_dir;
		new_y += sin(player->rotate_angle) * walk_dir;
	}
	else if (straf)
	{
		new_x = player->x + straf * (cos(player->rotate_angle - (M_PI / 2)));
		new_y = player->y + straf * (sin(player->rotate_angle - (M_PI / 2)));
	}
	else
	{
		new_x = player->x + cos(player->rotate_angle) * walk_dir;
		new_y = player->y + sin(player->rotate_angle) * walk_dir;
	}
	player_acutal(map, player, new_x, new_y);
}

void		player_movement(t_map *map, t_player *player)
{
	int		turn_dir;
	float	walk_dir;
	float	straf;

	turn_dir = player->turn_dir_l ? -1 : 0;
	turn_dir = player->turn_dir_r ? 1 : turn_dir;
	turn_dir = player->turn_dir_r && player->turn_dir_l ? 0 : turn_dir;
	walk_dir = player->walk_dir_d ? -1 : 0;
	walk_dir = player->walk_dir_u ? 1 : walk_dir;
	walk_dir = player->walk_dir_d && player->walk_dir_u ? 0 : walk_dir;
	straf = player->straf_r ? -1 : 0;
	straf = player->straf_l ? 1 : straf;
	straf = player->straf_r && player->straf_l ? 0 : straf;
	player->rotate_angle += turn_dir * player->rotate_speed;
	walk_dir *= player->move_speed;
	straf *= (player->move_speed / STRAF_FACTOR);
	player_movement_2(map, player, walk_dir, straf);
}
