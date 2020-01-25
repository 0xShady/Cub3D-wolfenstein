/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:52:56 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/25 22:26:34 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	exit_on_success(t_game *game)
{
	free_all(game);
	exit(EXIT_SUCCESS);
	return (1);
}

static int	key_press_hook(int key, void *game)
{
	t_game	*ptr_game;

	ptr_game = (t_game *)game;
	if (key == ESC)
		exit_on_success(game);
	if (key == UP)
		ptr_game->player.walk_dir_u = 1;
	if (key == DOWN)
		ptr_game->player.walk_dir_d = 1;
	if (key == R_AROW)
		ptr_game->player.turn_dir_r = 1;
	if (key == L_AROW)
		ptr_game->player.turn_dir_l = 1;
	if (key == LEFT)
		ptr_game->player.straf_l = 1;
	if (key == RIGHT)
		ptr_game->player.straf_r = -1;
	if (key == ARROW_DOWN)
		if (ptr_game->res_center > ptr_game->mid / 3)
			ptr_game->res_center -= 20;
	if (key == ARROW_UP)
		if (ptr_game->res_center < ptr_game->mid * 3)
			ptr_game->res_center += 20;
	return (0);
}

static int	key_release_hook(int key, void *game)
{
	t_game	*ptr_game;

	ptr_game = (t_game *)game;
	if (key == UP)
		ptr_game->player.walk_dir_u = 0;
	if (key == DOWN)
		ptr_game->player.walk_dir_d = 0;
	if (key == R_AROW)
		ptr_game->player.turn_dir_r = 0;
	if (key == L_AROW)
		ptr_game->player.turn_dir_l = 0;
	if (key == LEFT)
		ptr_game->player.straf_l = 0;
	if (key == RIGHT)
		ptr_game->player.straf_r = 0;
	return (0);
}

int			keys_set(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 0, key_press_hook, game);
	mlx_hook(game->win_ptr, 3, 0, key_release_hook, game);
	mlx_hook(game->win_ptr, 17, 0, exit_on_success, game);
	return (0);
}
