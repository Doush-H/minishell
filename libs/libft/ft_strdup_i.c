/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:36:29 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/19 16:41:14 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_i(const char *s1, size_t n)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = ft_calloc(n + 1, sizeof(char));
	if (!mem)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{	
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
