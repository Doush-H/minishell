/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:42:15 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/07 19:32:20 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while (src != NULL && *src != '\0')
	{
		if (i + 1 < (int) dstsize)
		{
			*dst = *src;
			dst++;
		}
		src++;
		i++;
	}
	if (dstsize)
		*dst = '\0';
	return (i);
}
