/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars_here_doc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:11:15 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/21 13:43:24 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	len_helper_here_doc(char *str, t_set_vars *vars, char **env)
{
	char	*tmp;

	if (str[vars->i] == '$')
	{
		vars->var_name = get_var_name(&(str[(vars->i) + 1]));
		tmp = env_get_value(env, vars->var_name);
		vars->j += ft_strlen(tmp);
		if (str[vars->i + 1] == '?')
			free(tmp);
		vars->i += ft_strlen(vars->var_name);
		free(vars->var_name);
	}
	else
		vars->j++;
}

//vars.j is the len
int	get_expanded_len_here_doc(char *str, char **env)
{
	t_set_vars	vars;

	vars.i = 0;
	vars.j = 0;
	while (str != NULL && str[vars.i] != '\0')
	{
		len_helper_here_doc(str, &vars, env);
		vars.i++;
	}
	return (vars.j);
}

void	set_helper_here_doc(char *str, char **env, t_set_vars *vars)
{
	char	*tmp;

	if (str[vars->i] == '$')
	{
		vars->var_name = get_var_name(&(str[vars->i + 1]));
		tmp = env_get_value(env, vars->var_name);
		vars->value = ft_strdup(tmp);
		if (str[vars->i + 1] == '?')
			free(tmp);
		ft_strlcpy(&(vars->ret_str[vars->j]), vars->value,
			ft_strlen(vars->value) + 1);
		vars->j += ft_strlen(vars->value);
		vars->i += ft_strlen(vars->var_name) + 1;
		free(vars->var_name);
		free(vars->value);
	}
	else
		vars->ret_str[vars->j++] = str[vars->i++];
}

// quotes = 0 (squotes = 0 | dquotes = 0)
// quotes = 1 (squotes = 0 | dquotes = 1)
// quotes = 2 (squotes = 1 | dquotes = 0)
// quotes = 3 (squotes = 1 | dquotes = 1)
char	*set_vars_here_doc(char *str, char **env)
{
	t_set_vars	vars;

	vars.i = 0;
	vars.j = 0;
	vars.var_name = NULL;
	vars.ret_str = ft_calloc(get_expanded_len_here_doc(str, env) + 1,
			sizeof(char));
	while (str != NULL && str[vars.i] != '\0')
		set_helper_here_doc(str, env, &vars);
	return (vars.ret_str);
}
