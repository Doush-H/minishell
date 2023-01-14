/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:06:15 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/16 19:23:17 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/**
 * @brief Executes a built in command
 * 
 * @param child The child pointer with file descriptors 
 * @param env environment from global
 * @return 0 when ok and 1 when error
 */
int	builtin_exec(t_child *child, t_global *global)
{
	if (ft_strncmp(child->cmd[0], "echo", ft_strlen("echo") + 1) == 0)
		return (builtin_echo(child));
	else if (ft_strncmp(child->cmd[0], "pwd", ft_strlen("pwd") + 1) == 0)
		return (builtin_pwd());
	else if (ft_strncmp(child->cmd[0], "export", ft_strlen("export") + 1) == 0)
		return (builtin_export(child, global->env));
	else if (ft_strncmp(child->cmd[0], "env", ft_strlen("env") + 1) == 0)
		return (builtin_env(global->env, child));
	else if (ft_strncmp(child->cmd[0], "cd", ft_strlen("cd") + 1) == 0)
		return (builtin_cd(child, global->env));
	else if (ft_strncmp(child->cmd[0], "unset", ft_strlen("unset") + 1) == 0)
		return (builtin_unset(child, global->env));
	else if (ft_strncmp(child->cmd[0], "exit", ft_strlen("exit") + 1) == 0)
		return (builtin_exit(child, global));
	else
		return (1);
}
