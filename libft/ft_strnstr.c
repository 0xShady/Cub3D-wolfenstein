/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:48:39 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/23 05:48:44 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = i;
		x = 0;
		while (str[j] == to_find[x] && j < len)
		{
			if (to_find[x + 1] == '\0')
				return ((char *)&str[i]);
			j++;
			x++;
		}
		i++;
	}
	return (0);
}
