/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:36:29 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/07 14:28:56 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;
	int		i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	mem = ft_calloc(1, ft_strlen(s1) + 1);
	if (!mem)
		return (NULL);
	while (s1[i] != '\0')
	{	
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
