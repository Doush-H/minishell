/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dredir_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:02:01 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/19 17:32:01 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	*rem_dredir_in(char *str)
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
		if (is_dredir_in(tmp[i]) == -1)
		{
			ret = ft_strjoin_free(ret, tmp[i]);
			ret = ft_strjoin_free(ret, " ");
		}
		else
			i++;
		i++;
	}
	if (tmp != NULL)
		ft_free_split(tmp);
	if (str != NULL)
		free(str);
	return (ret);
}

int	is_dredir_in_split(char **str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != NULL)
	{
		if (ft_strlen(str[i]) == 2 && str[i][0] == '<' && str[i][1] == '<')
			return (i);
		i++;
	}
	return (-1);
}

int	is_dredir_in(char *str)
{
	if (ft_strlen(str) == 2 && str[0] == '<' && str[1] == '<')
		return (1);
	return (-1);
}
