/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:48:58 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/23 05:49:01 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getlines(int fd, char *str)
{
	char			*temp;
	int				ret;
	char			*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = 0;
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(str, '\n') == NULL)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) < 0)
		{
			free(buffer);
			return (0);
		}
		buffer[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
		if (ret == 0 || str[0] == '\0')
			break ;
	}
	free(buffer);
	return (str);
}

int		ft_error(int fd, char **line)
{
	char			c;

	if (fd < 0)
		return (1);
	if (read(fd, &c, 0) < 0)
		return (1);
	if (!line)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static	char	*str;
	size_t			len;
	char			*temp;

	if (ft_error(fd, line))
		return (-1);
	if ((str = ft_getlines(fd, str)) == NULL)
		return (0);
	if (!(ft_strchr(str, '\n')))
	{
		if (!(*line = ft_strdup(str)))
			return (-1);
		free(str);
		str = NULL;
		return (0);
	}
	else
	{
		len = ft_strchr(str, '\n') - str;
		temp = str;
		*line = ft_substr(str, 0, len);
		str = ft_strdup(str + len + 1);
		free(temp);
		return (1);
	}
}
