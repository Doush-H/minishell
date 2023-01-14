/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:20:53 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/20 16:44:19 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/**
 * @brief Cd's into the given directory
 * 
 * @param cmd as { "cd", "DIR" }
 * @return int || 0 = SUCCESS | 1 = ERROR
 */
int	builtin_cd(t_child *child, char **env)
{
	char	temp[PATH_MAX];
	char	*temps;

	if (close(STDIN_FILENO) < 0 && close(STDOUT_FILENO) < 0)
		return (1);
	if (!(env && child && child->cmd))
		return (1);
	if (env_get_value(env, "PWD"))
		env_update(env, "OLDPWD", env_get_value(env, "PWD"), 0);
	if (!child->cmd[1] && env_get(env, "HOME"))
		chdir(env_get_value(env, "HOME"));
	else if (child->cmd[1] && chdir(child->cmd[1]))
	{
		temps = ft_strjoin("cd: ", child->cmd[1]);
		perror(temps);
		free(temps);
		return (1);
	}
	ft_bzero(temp, PATH_MAX);
	getcwd(temp, PATH_MAX);
	env_update(env, "PWD", temp, 0);
	return (0);
}
