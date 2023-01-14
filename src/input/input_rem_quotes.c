/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_rem_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:33:05 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/16 20:56:32 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	*remove_first_character(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}	
	str[i -1] = '\0';
	return (str);
}

void	first_quote(int *i, char *str, int *status)
{
	if (str[(*i)] == '\"')
	{
		*status = 1;
		remove_first_character(&str[(*i)]);
	}
	else if (str[(*i)] == '\'')
	{
		*status = 2;
		remove_first_character(&str[(*i)]);
	}
	else
		(*i)++;
}

char	*rem_quotes(char *str)
{
	int		status;
	int		i;

	i = 0;
	status = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (status == 0)
			first_quote(&i, str, &status);
		else if (status == 1 && str[i] == '\"')
		{
			status = 0;
			remove_first_character(&str[i]);
		}
		else if (status == 2 && str[i] == '\'')
		{
			status = 0;
			remove_first_character(&str[i]);
		}
		else
			i++;
	}
	return (ft_strdup(str));
}

char	**input_rem_quotes(char **input)
{
	int		i;
	char	**tmp;

	i = 0;
	if (input == NULL)
		return (NULL);
	tmp = malloc((split_len(input) + 1) * sizeof(char *));
	while (input[i] != NULL)
	{
		tmp[i] = rem_quotes(input[i]);
		i++;
	}
	tmp[i] = NULL;
	ft_free_split(input);
	return (tmp);
}
