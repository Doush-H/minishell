/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:31:21 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/19 16:37:48 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Gets current location of the searched name | NOT ALLOCATED
 * 
 * @param env 
 * @param name 
 * @return char** 
 */
char	**env_get(char **env, char *name)
{
	int	i;

	if (!name)
		return (NULL);
	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0
			&& (env[i][ft_strlen(name)] == '='
			|| env[i][ft_strlen(name)] == '\0'))
			return (&env[i]);
		i++;
	}
	return (NULL);
}

/**
 * @brief Updates environment variable or creates new one if not found
 * | NOT ALLOCATED
 * @param env 
 * @param name 
 * @param value 
 * @return char** to current changed variable
 */
char	**env_update(char **env, char *name, char *value, int equal_sign)
{
	char	**temp;

	if (!env || !name || !value)
		return (NULL);
	temp = env_get(env, name);
	if (temp)
	{
		free(*temp);
		if (*value == '\0' && equal_sign == 0)
			*temp = ft_strdup(name);
		else
			*temp = ft_strjoin_free(ft_strjoin(name, "="), value);
		return (temp);
	}
	else
	{
		temp = env_extend(env);
		if (!temp)
			return (NULL);
		if (*value == '\0' && equal_sign == 0)
			*temp = ft_strdup(name);
		else
			*temp = ft_strjoin_free(ft_strjoin(name, "="), value);
		return (temp);
	}
}

/**
 * @brief Get value of name | NOT ALLOCATED
 *
 * @param env 
 * @param name 
 * @return char* NULL if not found || Pointer
 * if name found and after '=' character
 */
char	*env_get_value(char **env, char *name)
{
	char	**temp;
	char	*variable;
	int		i;

	if (name && ft_strncmp(name, "?", 1) == 0)
		return (ft_itoa(WEXITSTATUS(g_exit_code)));
	temp = NULL;
	temp = env_get(env, name);
	if (!temp)
		return (NULL);
	variable = *temp;
	i = 0;
	while (variable[i])
	{
		if (variable[i] == '=')
			return (&variable[i] + 1);
		i++;
	}
	return (&variable[i]);
}

/**
 * @brief Gets the next free space in the env | NOT ALLOCATED
 *
 * @param env
 * @return char**
 */
char	**env_extend(char **env)
{
	int	i;

	i = 0;
	while (env[i] && i < 1023)
		i++;
	if (i >= 1023)
		return (NULL);
	env[i + 1] = NULL;
	env[i] = (char *) 0x1;
	return (&env[i]);
}
