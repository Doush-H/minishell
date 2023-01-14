/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_where.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:44:43 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/20 16:33:09 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "children.h"

char	**where_get_paths(char **env);
char	*child_where_search(char **paths, char *path, char *cmd);

/**
 * @brief Gets the location of a exec | ALLOCATES
 * 
 * @param cmd 
 * @param env 
 * @return char* 
 */
char	*child_where( char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*temp;

	paths = where_get_paths(env);
	i = 0;
	if (!paths)
		return (cmd);
	while (paths[i])
	{
		temp = child_where_search(paths, paths[i], cmd);
		if (temp)
			return (temp);
		i++;
	}
	ft_free_split(paths);
	return (cmd);
}

char	**where_get_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i] && ft_strncmp("PATH=", env[i], 5))
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(&env[i][5], ':');
	return (paths);
}

char	*child_where_search(char **paths, char *path, char *cmd)
{
	char	*res;

	res = NULL;
	path = ft_strjoin(path, "/");
	res = ft_strjoin(path, cmd);
	free(path);
	if (ft_strchr(cmd, '/') != 0)
	{
		free(res);
		res = ft_strdup(cmd);
	}
	if (access(res, X_OK) == 0)
	{
		ft_free_split(paths);
		return (res);
	}
	free(res);
	return (NULL);
}
