/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:53:13 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/23 06:13:44 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*read_path(char *line)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (line[i] == ' ')
		i++;
	len = i;
	while (line[len] && line[len] != ' ')
		len++;
	str = ft_substr(line, i, len);
	return (str);
}

static void	read_resolution(char *line, t_game *game)
{
	int	i;

	i = 1;
	game->res_x = ft_atoi(&line[i]);
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	game->res_y = ft_atoi(&line[i]);
}

static int	check_floor_ceilling(char **split)
{
	int		i;
	char	*number;

	i = 0;
	while (split[i])
	{
		number = ft_strtrim(split[i], " ");
		if (!ft_isallnumber(number))
			return (-1);
		free(number);
		i++;
	}
	if (i != 3)
		return (-1);
	return (1);
}

static int	read_floor_ceiling(char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split(line, ',');
	if (check_floor_ceilling(split) == -1)
		return (-1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || g < 0 || b < 0)
		return (-1);
	free_split(split);
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int			parse_file_game(int fd, char *line, t_game *game)
{
	int		ret;
	int		end;

	end = 0;
	while (end != 8 && (ret = get_next_line(fd, &line)) > 0)
	{
		if (*line == 'R' && ++end)
			read_resolution(line, game);
		else if (line[0] == 'N' && line[1] == 'O' && ++end)
			game->tex[TEX_NO].path = read_path(&line[2]);
		else if (line[0] == 'S' && line[1] == 'O' && ++end)
			game->tex[TEX_SO].path = read_path(&line[2]);
		else if (line[0] == 'W' && line[1] == 'E' && ++end)
			game->tex[TEX_WE].path = read_path(&line[2]);
		else if (line[0] == 'E' && line[1] == 'A' && ++end)
			game->tex[TEX_EA].path = read_path(&line[2]);
		else if (line[0] == 'S' && ++end)
			game->tex[TEX_S].path = read_path(&line[1]);
		else if (*line == 'F' && ++end)
			game->f = read_floor_ceiling(&line[1]);
		else if (*line == 'C' && ++end)
			game->c = read_floor_ceiling(&line[1]);
		free(line);
	}
	return (ret);
}
