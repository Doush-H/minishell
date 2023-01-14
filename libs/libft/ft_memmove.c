/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixbruggemann <felixbruggemann@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:54:44 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/03 21:52:51 by felixbrugge      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*from;
	char			*to;

	from = src;
	to = dst;
	if (!dst && !src)
		return (0);
	if (from > to)
		while (len--)
			*to++ = *from++;
	else
	{
		to += len -1;
		from += len -1;
		while (len--)
			*to-- = *from--;
	}
	return (dst);
}
