/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:52:41 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/23 06:13:30 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_game_player_dir(char coord)
{
	if (coord == 'N')
		return (270);
	else if (coord == 'W')
		return (180);
	else if (coord == 'S')
		return (90);
	else if (coord == 'E')
		return (0);
	return (-1);
}

void	log_global_error(char *s, t_game *game)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	error_global(t_game *game)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(strerror(errno), 2);
	free_game(game);
	exit(EXIT_FAILURE);
}

void	error_global_close_fd(int fd, t_game *game)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(strerror(errno), 2);
	close(fd);
	free_game(game);
	exit(EXIT_FAILURE);
}
