/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:53:48 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/15 00:05:44 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	builtin_export_print(char **env);
static int	export_update(char **env, char *text);
char		*convert_to_name(char *text);
char		*convert_to_value(char *text);

/**
 * @brief Mimiks the functionality from export 
 * 
 * @param cmd as { "export", "NAME=VALUE"}
 * @param env 
 * @return int 
 */
int	builtin_export(t_child *child, char **env)
{
	int	i;

	if (close(STDIN_FILENO) < 0)
		return (1);
	if (!env || !child->cmd)
		return (1);
	if (!child->cmd[1])
		return (builtin_export_print(env));
	if (close(STDOUT_FILENO) < 0)
		return (1);
	i = 1;
	while (child->cmd[i])
	{
		export_update(env, child->cmd[i]);
		i++;
	}
	return (0);
}

/**
 * @brief Updates the value given in the text
 * 
 * @param env 
 * @param text 
 * @return int 
 */
static int	export_update(char **env, char *text)
{
	char	*name;
	char	*value;
	int		is_equal_sign;

	if (!env || !text)
		return (1);
	is_equal_sign = 0;
	name = NULL;
	value = NULL;
	name = convert_to_name(text);
	value = convert_to_value(text);
	if (ft_protect(2, name, value))
		return (1);
	if (ft_strnstr(text, "=", ft_strlen(text)))
		is_equal_sign = 1;
	if (!env_update(env, name, value, is_equal_sign))
		return (1);
	free(name);
	free(value);
	return (0);
}

/**
 * @brief gets name of text | ALLOCATES
 * 
 * @param text 
 * @return char* | NULL = ERROR
 */
char	*convert_to_name(char *text)
{
	int		i;
	char	*temp;
	char	*res;

	if (!text)
		return (NULL);
	i = 0;
	temp = NULL;
	temp = ft_strdup(text);
	if (!temp)
		return (NULL);
	while (temp[i] && temp[i] != '=')
		i++;
	res = NULL;
	res = (ft_strdup_i(temp, i));
	free(temp);
	return (res);
}

/**
 * @brief | ALLOCATES
 * 
 * @param text 
 * @return char* 
 */
char	*convert_to_value(char *text)
{
	int		i;
	char	*temp;
	char	*res;

	if (!text)
		return (NULL);
	i = 0;
	temp = NULL;
	temp = ft_strdup(text);
	if (!temp)
		return (NULL);
	while (temp[i] && temp[i] != '=')
		i++;
	res = NULL;
	res = (ft_strdup_i(&temp[i + 1], ft_strlen(temp) - i));
	free(temp);
	return (res);
}

/**
 * @brief Printfs the Environmental variables like the bash command export
 * 
 * @param env 
 * @return int 
 */
static int	builtin_export_print(char **env)
{
	int	i;
	int	j;

	j = 0;
	while (env[j])
	{
		i = 0;
		printf("declare -x ");
		while (env[j][i] && env[j][i] != '=')
			printf("%c", env[j][i++]);
		if (env[j][i] == '=')
		{
			printf("%c", env[j][i]);
			i++;
			printf("%c", '"');
			while (env[j][i])
				printf("%c", env[j][i++]);
			printf("%c", '"');
		}
		printf("\n");
		j++;
	}
	if (close(STDOUT_FILENO) < 0)
		return (1);
	return (0);
}
