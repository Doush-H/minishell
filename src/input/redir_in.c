/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:18:45 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/19 17:32:22 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	is_redir_in(char *str)
{
	if (ft_strlen(str) == 1 && str[0] == '<')
		return (1);
	return (-1);
}

char	*rem_redir_in(char *str)
{
	char	**tmp;
	char	*ret;
	int		i;

	str = rem_nl_tab(str);
	tmp = split_mod(str, ' ');
	i = 0;
	ret = NULL;
	while (tmp != NULL && tmp[i] != NULL)
	{
		if (is_redir_in(tmp[i]) == -1)
		{
			ret = ft_strjoin_free(ret, tmp[i]);
			ret = ft_strjoin_free(ret, " ");
		}
		else
			i++;
		i++;
	}
	ft_free_split(tmp);
	if (str != NULL)
		free(str);
	return (ret);
}

int	is_redir_in_split(char **str)
{
	int	i;

	i = split_len(str) - 1;
	while (str != NULL && i >= 0)
	{
		if (ft_strlen(str[i]) == 1 && str[i][0] == '<')
			return (i);
		i--;
	}
	return (-1);
}
