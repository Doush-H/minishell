/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:20:53 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/19 18:00:39 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int		is_only_digits(char *str);
int		setup_pipes_exit(t_child *child);
void	helper(t_global *global, t_child *child);

/**
 * @brief Cd's into the given directory
 * 
 * @param cmd as { "cd", "DIR" }
 * @return int 
 */
int	builtin_exit(t_child *child, t_global *global)
{
	close(STDIN_FILENO);
	if (!child->cmd)
		return (1);
	if (!child->cmd[1])
	{
		printf("exit\n");
		global_free(global);
		close(STDOUT_FILENO);
		exit(g_exit_code % 256);
	}
	else if (ft_2ptrlen((void **)child->cmd) == 2)
		helper(global, child);
	else
		ft_putstr_fd("exit\nexit: too many arguments\n", STDERR_FILENO);
	close(STDOUT_FILENO);
	return (1);
}

void	helper(t_global *global, t_child *child)
{
	int	i;

	printf("exit\n");
	if (is_only_digits(child->cmd[1]))
	{
		ft_putstr_fd("bash: exit: numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	close(STDOUT_FILENO);
	i = ft_atoi(child->cmd[1]);
	global_free(global);
	exit(i);
}

int	is_only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
