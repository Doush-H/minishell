/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_add_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:21:55 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/22 23:39:50 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

//Returns the len of a string after adding spaces before and after redirections
int	len_after_adding_spaces(const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (is_valid_redir(str, i) > -1)
		{
			len += is_valid_redir(str, i) + 2;
			i += is_valid_redir(str, i);
		}
		i++;
		len++;
	}
	return (len);
}

//Copy and skip the single quotes inside of str (single quotes are also copied)
void	copy_skip_squotes(char *ret_str, char *str, int *i, int *j)
{
	if (str[*i] == '\'' && ft_strchr(&(str[(*i) + 1]), '\'') != 0)
	{
		ret_str[*j] = str[*i];
		(*i)++;
		(*j)++;
		while (str[*i] != '\'' && str[*i] != '\0')
		{
			ret_str[*j] = str[*i];
			(*i)++;
			(*j)++;
		}
		if (str[*i] == '\'')
		{
			ret_str[*j] = str[*i];
			(*i)++;
			(*j)++;
		}
	}
}

//Copy and skip the double quotes inside of str (double quotes are also copied)
void	copy_skip_dquotes(char *ret_str, char *str, int *i, int *j)
{
	if (str[*i] == '\"' && ft_strchr(&(str[(*i) + 1]), '\"') != 0)
	{
		ret_str[*j] = str[*i];
		(*i)++;
		(*j)++;
		while (str[*i] != '\"' && str[*i] != '\0')
		{
			ret_str[*j] = str[*i];
			(*i)++;
			(*j)++;
		}
		if (str[*i] == '\"')
		{
			ret_str[*j] = str[*i];
			(*i)++;
			(*j)++;
		}
	}
}

int	put_spaces(char *ret_str, char *str, int *i, int *j)
{
	int		tmp_i;

	tmp_i = -1;
	tmp_i = is_valid_redir(str, *i);
	if (tmp_i > -1)
	{
		ret_str[(*j)++] = ' ';
		while (tmp_i-- > -1)
		{
			ret_str[(*j)++] = str[(*i)++];
		}
		ret_str[(*j)++] = ' ';
	}
	else if (tmp_i == -1)
	{
		ft_putstr_fd("Syntax error in redirs (put_spaces())\n", STDERR_FILENO);
		ft_protect(3, str, ret_str, NULL);
		return (-1);
	}
	return (0);
}

char	*add_spaces(char *str)
{
	int		i;
	int		j;
	char	*ret_str;

	i = 0;
	j = 0;
	ret_str = ft_calloc(len_after_adding_spaces(str) + 1, sizeof(char));
	if (ret_str == NULL)
	{
		free(str);
		return (NULL);
	}
	while (str[i] != '\0')
	{
		copy_skip_squotes(ret_str, str, &i, &j);
		copy_skip_dquotes(ret_str, str, &i, &j);
		if (put_spaces(ret_str, str, &i, &j) == -1)
			return (NULL);
		if (str[i] != '\0')
			ret_str[j++] = str[i++];
	}
	free(str);
	return (ret_str);
}
