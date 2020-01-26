/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 05:52:38 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/26 20:39:12 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	take_texture(t_game *game, t_tex *tex)
{
	int y;
	int x;

	if (!(tex->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		tex->path, &tex->width, &tex->height)))
		return (-1);
	if (!(tex->data = (int *)mlx_get_data_addr(tex->ptr,
		&tex->bpp, &tex->size_l, &tex->endian)))
		return (-1);
	y = -1;
	while (++y < tex->height)
	{
		x = -1;
		while (++x < tex->width)
			tex->tex[x][y] = (int)tex->data[y * tex->width + x];
	}
	return (1);
}

void		init_textute(t_game *game)
{
	if (take_texture(game, &game->tex[TEX_NO]) < 0)
		log_global_error("North texture not Sepcfiead  or unavailable ", game);
	if (take_texture(game, &game->tex[TEX_SO]) < 0)
		log_global_error("South texture not Sepcfiead  or unavailable", game);
	if (take_texture(game, &game->tex[TEX_WE]) < 0)
		log_global_error("West texture not Sepcfiead  or unavailable", game);
	if (take_texture(game, &game->tex[TEX_EA]) < 0)
		log_global_error("East texture not Sepcfiead  or unavailable", game);
	if (take_texture(game, &game->tex[TEX_S]) < 0)
		log_global_error("Sprite not Sepcfiead or unavailable", game);
	if (take_texture(game, &game->tex[TEX_LIFE]) < 0)
		log_global_error("Life bar unavailable", game);
	if (take_texture(game, &game->tex[TEX_SCOOP]) < 0)
		log_global_error("Scoop unavailable", game);
}
