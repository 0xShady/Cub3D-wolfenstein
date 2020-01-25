/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 05:47:16 by ael-fadi          #+#    #+#             */
/*   Updated: 2020/01/23 05:47:18 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *ret;

	ret = dst;
	if (!((unsigned char*)dst) && !((unsigned char*)src))
		return (dst);
	if (!ft_memcmp(dst, src, n))
		return (dst);
	while (n--)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		src++;
	}
	return (ret);
}
