/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:22:09 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/19 17:58:16 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_len_until_char(char *str, char c, char char_og)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		if (c == char_og && str[i] == '\''
			&& ft_strchr(&(str[i + 1]), '\'') != NULL)
		{	
			i += get_len_until_char(&str[i + 1], '\'', char_og);
		}
		else if (c == char_og && str[i] == '\"'
			&& ft_strchr(&(str[i + 1]), '\"') != NULL)
		{
			i += get_len_until_char(&str[i + 1], '\"', char_og);
		}
		else
			i++;
	}
	while (str[i] != '\0' && str[i] != char_og)
		i++;
	return (i);
}

int	get_len(char *str, char c)
{
	int	size;

	size = 0;
	if (*str == '\"' && ft_strchr(str + 1, '\"') != NULL)
		size = get_len_until_char(str + 1, '\"', c) + 1;
	else if (*str == '\'' && ft_strchr(str + 1, '\'') != NULL)
		size = get_len_until_char(str + 1, '\'', c) + 1;
	else
		size = get_len_until_char(str, c, c);
	return (size);
}

int	word_count(char *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		str = skip_char(str, c);
		if (str == NULL && c == '|')
		{
			free(str);
			return (0);
		}
		if (*str != '\0')
			count++;
		str = skip_word(str, c);
	}
	return (count);
}

//frees the input str
char	*rem_nl_tab(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*ret_str;

	i = 0;
	j = 0;
	size = 0;
	while (str != NULL && str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '\t')
			size++;
		i++;
	}
	ret_str = ft_calloc(size + 1, sizeof(char));
	i = 0;
	while (str != NULL && str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '\t')
			ret_str[j++] = str[i];
		i++;
	}
	free(str);
	return (ret_str);
}
