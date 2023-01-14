/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:17:30 by fbruggem          #+#    #+#             */
/*   Updated: 2022/04/02 14:50:59 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_part(char *s, char c, int skip_word);
static char	*get_word(char *s, char c);
static char	**free_split(char **res);
static int	get_nbr_of_words(char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	*mem;
	char	**res;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	res = ft_calloc(get_nbr_of_words((char *) s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (res);
	mem = (char *)s;
	mem = skip_part(mem, c, 0);
	while (*mem != '\0')
	{
		res[i] = get_word(mem, c);
		if (!res[i])
			return (free_split(res));
		mem = skip_part(mem, c, 1);
		mem = skip_part(mem, c, 0);
		i++;
	}
	return (res);
}

static char	*skip_part(char *s, char c, int skip_word)
{
	while (*s == c && *s != '\0' && skip_word == 0)
		s++;
	while (*s != c && *s != '\0' && skip_word == 1)
		s++;
	return (s);
}

static char	*get_word(char *s, char c)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	res = ft_calloc(i + 1, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	get_nbr_of_words(char *s, char c)
{
	int	i;

	i = 0;
	s = skip_part(s, c, 0);
	while (*s != '\0')
	{
		s = skip_part(s, c, 1);
		s = skip_part(s, c, 0);
		i++;
	}
	return (i);
}

static char	**free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}
