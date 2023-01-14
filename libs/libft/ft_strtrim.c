/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:52:24 by fbruggem          #+#    #+#             */
/*   Updated: 2022/03/31 14:19:55 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *set, char const c);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*mem;

	if (s1 == NULL)
		return (NULL);
	while (is_in_set(set, *s1) && ft_strlen(s1))
		s1++;
	i = ft_strlen(s1) -1;
	while (is_in_set(set, s1[i]) && i > -1)
		i--;
	mem = ft_calloc(i + 2, 1);
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s1, i + 2);
	mem[i + 1] = '\0';
	return (mem);
}

static int	is_in_set(char const *set, char const c)
{
	int		res;
	size_t	i;

	i = 0;
	res = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			res = 1;
		i++;
	}
	return (res);
}
