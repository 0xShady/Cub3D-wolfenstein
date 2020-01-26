/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 05:52:38 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/26 20:39:01 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				game_loop(t_game *game)
{
	player_movement(&game->map, &game->player);
	cast_all_ray(game, &game->player);
	ft_render_wall(game, &game->player);
	generete_sprite(game, &game->player);
	life_bar(game);
	ft_scoop(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr,
	0, 0);
	return (0);
}

void			window_initialization(t_game *game, t_img *img)
{
	if (!(game->mlx_ptr = mlx_init()))
		error_global(game);
	if (!(game->win_ptr = mlx_new_window(game->mlx_ptr,
		game->res_x, game->res_y, "cub3d")))
		error_global(game);
	img->img_ptr = mlx_new_image(game->mlx_ptr, game->res_x, game->res_y);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
	&img->size_l, &img->endian);
}

int				main(int argc, char **argv)
{
	t_game	*game;

	setbuf(stdout, NULL);
	if (argc < 2 || argc > 3)
		log_global_error("number of argument must be 2 or 3", NULL);
	game = game_initialization();
	read_file_game(argv[1], (argc == 3 ? argv[2] : NULL), game);
	game->res_center = game->res_y / 2;
	game->mid = game->res_center;
	window_initialization(game, &game->img);
	init_player_on_map(&game->map, &game->player);
	init_textute(game);
	keys_set(game);
	mlx_loop_hook(game->mlx_ptr, game_loop, game);
	if (game->save)
		create_bmp(game);
	else
		mlx_loop(game->mlx_ptr);
	return (EXIT_SUCCESS);
}
