/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:20:53 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/15 00:05:10 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/**
 * @brief Unset a env variable
 * 
 * @param cmd 
 * @param env 
 * @return int 
 */
int	builtin_unset(t_child *child, char **env)
{
	int		i;
	int		c;
	char	**temp;

	if (close(STDIN_FILENO) < 0 && close(STDOUT_FILENO) < 0)
		return (1);
	if (!env || !child || !child->cmd)
		return (1);
	c = 1;
	while (child->cmd[c])
	{
		i = 1;
		temp = env_get(env, child->cmd[c]);
		if (!temp)
			break ;
		free(*temp);
		while (temp[i])
		{
			temp[i -1] = temp[i];
			i++;
		}
		temp[i -1] = NULL;
		c++;
	}
	return (0);
}
