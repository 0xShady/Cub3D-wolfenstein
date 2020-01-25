/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:48:48 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/23 05:48:50 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*trimed;

	if (!s || !set)
		return (NULL);
	start = 0;
	end = 0;
	len = ft_strlen(s);
	while (ft_strchr(set, s[start]))
		start++;
	while (ft_strchr(set, s[len]))
	{
		len--;
		end++;
	}
	if (start >= (int)ft_strlen(s))
	{
		trimed = (char *)malloc(sizeof(char));
		trimed[0] = '\0';
		return (trimed);
	}
	trimed = ft_substr(s, start, ft_strlen(s) - (start + end) + 1);
	return (trimed);
}
