/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixbruggemann <felixbruggemann@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:50:24 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/03 21:53:17 by felixbrugge      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	ret;

	dstlen = 0;
	ret = ft_strlen(src) + ft_strlen(dst);
	while (dstsize != 0 && *dst != '\0')
	{
		dst++;
		dstlen++;
		dstsize--;
	}
	if (dstsize == 0)
		return (dstlen + ft_strlen(src));
	while (*src != '\0' && dstsize > 1)
	{
		*dst = *src;
		src++;
		dst++;
		dstsize--;
	}
	*dst = '\0';
	return (ret);
}
