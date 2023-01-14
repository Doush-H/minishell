/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:28:53 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/07 11:49:36 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && len-- > 0)
	{
		i = 0;
		while ((needle[i] == haystack[i] && i <= len) || needle[i] == '\0')
		{
			if (needle[i] == '\0')
				return ((char *) haystack);
			i++;
		}
		haystack++;
	}
	return (NULL);
}
