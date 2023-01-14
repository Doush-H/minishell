/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:11:58 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/18 16:34:26 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../input/input.h"

int	dredir_out_check(char **tmp, int i, t_global *global);
int	redir_out_check(char **tmp, int i, t_global *global);

//if portion of the str staring from index i 
// 	has redirection returned value is > -1
//return 0 == single redir
//return 1 == double redir
//return -1 == error
//return -2 == no redirections
int	is_valid_redir(const char *str, int i)
{
	if (str[i] == '<')
	{
		if (str[i + 1] != '<' && str[i + 1] != '>')
			return (0);
		if (str[i + 1] == '<' && str[i + 2] != '<' && str[i + 2] != '>')
			return (1);
		return (-1);
	}
	if (str[i] == '>')
	{
		if (str[i + 1] != '<' && str[i + 1] != '>')
			return (0);
		if (str[i + 1] == '>' && str[i + 2] != '<' && str[i + 2] != '>')
			return (1);
		return (-1);
	}
	return (-2);
}

int	set_redirs_out(char **tmp, t_global *glob)
{
	int		i;

	i = 0;
	while (tmp[i] != NULL)
	{
		if (redir_out_check(tmp, i, glob) || dredir_out_check(tmp, i, glob))
			return (1);
		i++;
	}
	return (0);
}

int	set_dredir_in(char	**tmp, t_global *global)
{
	int			j;
	int			lim;
	t_limiter	lm;

	j = 0;
	while (is_dredir_in_split(&tmp[j]) != -1 && tmp[j] != NULL)
	{
		lim = is_dredir_in_split(&tmp[j]) + 1;
		j += lim;
		if (tmp[j] == NULL)
			return (1);
		if (tmp[j][0] == '\"' || tmp[j][0] == '\'')
			lm.expand = 0;
		else
			lm.expand = 1;
		lm.lim = rem_quotes(tmp[j]);
		dlistadd_back(&global->children_head, dlistnew(NULL, NULL, NULL, lm));
	}
	return (0);
}

int	set_redir_in(char **tmp, t_global *global)
{
	t_child	*last_child;

	last_child = dlistlast(global->children_head);
	if (is_redir_in_split(tmp) != -1)
	{
		if (tmp[is_redir_in_split(tmp) + 1] == NULL)
			return (1);
		last_child->file_in = rem_quotes(tmp[is_redir_in_split(tmp) + 1]);
	}
	return (0);
}
