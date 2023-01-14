/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:57:45 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/15 00:06:32 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/**
 * @brief Mimics the functionality of env without params and options
 * 
 * @param env 
 * @return int || 0 = SUCCESS | 1 = ERROR
 */
int	builtin_env(char **env, t_child *child)
{
	int	i;

	i = 0;
	if (close(STDIN_FILENO) < 0)
		return (1);
	if (!env || !child->cmd)
		return (1);
	if (child->cmd[1])
		return (1);
	while (env[i])
	{
		if (ft_strnstr(env[i], "=", ft_strlen(env[i])))
			printf("%s\n", env[i]);
		i++;
	}
	if (close(STDOUT_FILENO) < 0)
		return (1);
	return (0);
}
