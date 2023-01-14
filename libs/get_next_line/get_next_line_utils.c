/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:41:30 by fbruggem          #+#    #+#             */
/*   Updated: 2022/04/24 13:08:13 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stringjoin(char const *s1, char const *s2)
{
	char	*mem;
	int		i;
	int		len;

	if (s1 == NULL || s2 == NULL)
		s1 = "";
	i = 0;
	len = strlength(s1, '\0') + strlength(s2, '\0');
	mem = malloc(len + 1);
	if (!mem)
		return (NULL);
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		mem[i] = s2[i - strlength(s1, '\0')];
		i++;
	}
	mem[i] = '\0';
	if (*s1 != '\0')
		free((char *) s1);
	return (mem);
}

size_t	strlength(const char *s, char end)
{
	int	i;

	i = 0;
	while (s[i] != end && s[i] != '\0')
		i++;
	return (i);
}

char	*stringdup(const char *s1, size_t nbr)
{
	char	*mem;
	int		i;

	i = 0;
	mem = malloc(strlength(s1, '\0') + 1);
	if (!mem)
		return (NULL);
	while (s1[i] != '\0' && nbr--)
	{	
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

int	char_exists(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}
