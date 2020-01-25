/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:53:09 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/25 14:25:06 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*parse_sprite_player(t_game *game, int row, int *player,
char *tmp_map)
{
	int		col;
	char	*str_row;

	col = -1;
	if (!(str_row = malloc(sizeof(*str_row) * game->map.map_col)))
		return (NULL);
	while (++col < game->map.map_col)
	{
		str_row[col] = tmp_map[col];
		if (ft_strcontaines(PLAYER_INIT_POS, str_row[col]))
		{
			game->map.player_dir = parse_game_player_dir(str_row[col]);
			game->map.player_x = col + 0.5;
			game->map.player_y = row + 0.5;
			(*player)++;
		}
		if (*player > 1)
		{
			game->map.player_x = -1;
			game->map.player_y = -1;
		}
		if (str_row[col] == '2')
			init_sprite(game, col, row);
	}
	return (str_row);
}

static int	ft_fucknorminte(char **line)
{
	int		i;
	int		idx;

	i = -1;
	idx = 0;
	while (ft_strcontaines(MAP_GAME, line[0][++i]) || line[0][i] == ' ')
		if (ft_strcontaines(MAP_GAME, line[0][i]))
			line[0][idx++] = line[0][i];
	return (idx);
}

static int	read_file_helper(int fd, char *line, char **map, int *row)
{
	int		ret;
	int		last_idx;
	int		idx;
	int		i;

	last_idx = -1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strcontaines(MAP_GAME, *line) && ++(*row) && (i = -1))
		{
			idx = ft_fucknorminte(&line);
			if (last_idx != idx && last_idx != -1)
				*map = ft_strjoin(*map, "Map_Error");
			last_idx = idx;
			ft_strlcpy(line, line, idx + 1);
			*map = ft_strjoin_free(*map, line);
		}
		else if (last_idx != -1)
			*map = ft_strjoin(*map, "Map_Error");
		free(line);
	}
	free(line);
	return ((ret < 0) ? ret : idx);
}

static int	parse_file_map(int fd, char *line, t_game *game, t_map *map)
{
	char	*tmp_map;
	int		row;
	int		player;

	tmp_map = NULL;
	if ((map->map_col = read_file_helper(fd, line, &tmp_map, &map->map_row))
		< 0)
		return (-1);
	if (!(map->map = (char **)malloc(sizeof(char *) * map->map_row)))
		return (-1);
	player = 0;
	row = -1;
	while (++row < map->map_row)
	{
		if (!(map->map[row] = parse_sprite_player(game, row, &player,
			&tmp_map[row * map->map_col])))
			return (-1);
	}
	free(tmp_map);
	return (1);
}

void		read_file_game(char *file, char *param2, t_game *game)
{
	int		fd;
	int		i;

	i = 0;
	if (!(ft_strnstr(file, ".cub", ft_strlen(file))))
		log_global_error("Unvailable file extension", game);
	if (ft_strncmp(param2, "–save", ft_strlen(param2)))
		game->save = 1;
	if (!(fd = open(file, O_RDONLY)))
		error_global_close_fd(fd, game);
	if (parse_file_game(fd, NULL, game) < 0)
		error_global_close_fd(fd, game);
	if (parse_file_map(fd, NULL, game, &game->map) < 0)
		error_global_close_fd(fd, game);
	check_game(game, &game->map);
	close(fd);
}
