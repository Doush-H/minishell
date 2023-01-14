/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_is_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:34:01 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/15 00:05:27 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/**
 * @brief Checks if the cmd is a builtin cmd
 * 
 * @param cmd 
 * @param env 
 * @return int 
 */
int	builtin_is_cmd(char **cmd, char **env)
{
	if (!cmd || !env)
		return (0);
	if (ft_strncmp(cmd[0], "echo", ft_strlen("echo") + 1) == 0)
		return (1);
	if (ft_strncmp(cmd[0], "pwd", ft_strlen("pwd") + 1) == 0)
		return (1);
	if (ft_strncmp(cmd[0], "export", ft_strlen("export") + 1) == 0)
		return (1);
	if (ft_strncmp(cmd[0], "env", ft_strlen("env") + 1) == 0)
		return (1);
	if (ft_strncmp(cmd[0], "cd", ft_strlen("cd") + 1) == 0)
		return (1);
	if (ft_strncmp(cmd[0], "unset", ft_strlen("unset") + 1) == 0)
		return (1);
	if (ft_strncmp(cmd[0], "exit", ft_strlen("exit") + 1) == 0)
		return (1);
	return (0);
}
