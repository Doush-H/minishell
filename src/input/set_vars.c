/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:38:49 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/21 11:47:47 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	*get_var_name(char *str)
{
	int		i;
	char	*var_name;

	i = 0;
	while (str[i] != '\0' && str[i] != '\'' && str[i] != '\"')
	{
		if (str[i] == ' ' || str[i] == '|' || str[i] == '<'
			|| str[i] == '>' || str[i] == '\\' || str[i] == '$')
		{
			break ;
		}
		i++;
	}
	var_name = ft_strdup_i(str, i);
	if (var_name == NULL )
		return (NULL);
	if (var_name[0] == '\0')
	{
		free(var_name);
		return (NULL);
	}
	return (var_name);
}

//vars->j = len
void	len_helper(char *str, t_set_vars *vars, char **env)
{
	char	*tmp;

	if (str[vars->i] == '\"' && ft_strchr(&str[vars->i + 1], '\"') != 0
		&& vars->quotes == 0)
	{
		vars->quotes = 1;
	}
	if (str[vars->i] == '\'' && ft_strchr(&str[vars->i + 1], '\'') != 0
		&& vars->quotes == 0)
	{
		vars->quotes = 2;
	}
	if (str[vars->i] == '$' && (vars->quotes == 0 || vars->quotes == 1))
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
int	get_expanded_len(char *str, char **env)
{
	t_set_vars	vars;

	vars.i = 0;
	vars.j = 0;
	vars.quotes = 0;
	while (str != NULL && str[vars.i] != '\0')
	{
		len_helper(str, &vars, env);
		vars.i++;
		if (str[vars.i] == '\'' && vars.quotes == 2)
		{
			vars.i++;
			vars.j++;
			vars.quotes = 0;
		}
		if (str[vars.i] == '\"' && vars.quotes == 1)
		{
			vars.i++;
			vars.j++;
			vars.quotes = 0;
		}
	}
	return (vars.j);
}

void	set_helper(char *str, char **env, t_set_vars *vars)
{
	char	*tmp;

	if (str[vars->i] == '\"' && ft_strchr(&str[vars->i + 1], '\"') != 0
		&& vars->quotes == 0)
		vars->quotes = 1;
	if (str[vars->i] == '\'' && ft_strchr(&str[vars->i + 1], '\'') != 0
		&& vars->quotes == 0)
		vars->quotes = 2;
	if (str[vars->i] == '$' && (vars->quotes == 0 || vars->quotes == 1))
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
char	*set_vars(char *str, char **env)
{
	t_set_vars	vars;

	vars.i = 0;
	vars.j = 0;
	vars.quotes = 0;
	vars.var_name = NULL;
	vars.ret_str = ft_calloc(get_expanded_len(str, env) + 1, sizeof(char));
	while (str != NULL && str[vars.i] != '\0')
	{
		set_helper(str, env, &vars);
		if (str[vars.i] == '\'' && vars.quotes == 2)
		{
			vars.ret_str[vars.j++] = str[vars.i++];
			vars.quotes = 0;
		}
		if (str[vars.i] == '\"' && vars.quotes == 1)
		{
			vars.ret_str[vars.j++] = str[vars.i++];
			vars.quotes = 0;
		}
	}
	return (vars.ret_str);
}

//old set_vars()
// char	*set_vars(char *str, char **env)
// {
// 	char	*ret_str;
// 	int		i;
// 	int		j;
// 	char 	*value;
// 	char	*var_name;
// 	int		squote;
// 	int		dquote;

// 	i = 0;
// 	j = 0;
// 	squote = 0;
// 	dquote = 0;
// 	var_name = NULL;
// 	ret_str = malloc(get_expanded_len(str, env) + 1);
// 	while (str != NULL && str[i] != '\0')
// 	{
// 		if (str[i] == '\"' && ft_strchr(&str[i + 1], '\"') != 0 && squote == 0)
// 			dquote = 1;
// 		if (str[i] == '\'' && ft_strchr(&str[i + 1], '\'') != 0 && dquote == 0)
// 			squote = 1;
// 		if (str[i] == '$' && squote == 0)
// 		{
// 			var_name = get_var_name(&(str[i + 1]));
// 			value = ft_strdup(env_get_value(env, var_name));
// 			ft_strlcpy(&(ret_str[j]), value, ft_strlen(value) + 1);
// 			j += ft_strlen(value);
// 			i += ft_strlen(var_name);
// 			free(var_name);
// 		}
// 		else
// 			ret_str[j++] = str[i];
// 		i++;
// 		if (str[i] == '\'' && squote == 1)
// 		{
// 			ret_str[j++] = str[i++];
// 			squote = 0;
// 		}
// 		if (str[i] == '\"' && dquote == 1)
// 		{
// 			ret_str[j++] = str[i++];
// 			dquote = 0;
// 		}
// 	}
// 	ret_str[j] = '\0';
// 	return (ret_str);
// }

///usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki