/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:46:55 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/23 05:46:59 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(int c)
{
	if (c == '\t' || c == '\r' || c == '\n' ||
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char const *s)
{
	long			nbr;
	long			sign;
	int				i;
	unsigned long	lon;

	lon = 9223372036854775807;
	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_iswhitespace((int)s[i]) && s[i])
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
		{
			sign = -1;
			nbr = -nbr;
		}
	while (ft_isdigit(s[i]) && s[i])
	{
		if ((unsigned long)nbr > lon / 10 ||
			((unsigned long)nbr == lon / 10 && ((unsigned long)nbr % 10) > 7))
			return (sign > 0 ? -1 : 0);
		nbr = nbr * 10 + (s[i++] - 48);
	}
	return (nbr * sign);
}
