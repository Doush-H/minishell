/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:57:10 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/09 16:13:44 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*mem;
	int		i;
	int		len;

	if (!s1)
		s1 = ft_strdup("");
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	mem = ft_calloc(1, len + 1);
	if (!mem)
		return (NULL);
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		mem[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	mem[i] = '\0';
	if (s1)
		free((void *) s1);
	return (mem);
}
