/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:41:07 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/22 23:38:35 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	dredir_out_check(char **tmp, int i, t_global *global)
{
	t_child	*last_child;
	char	*file;

	last_child = dlistlast(global->children_head);
	if (is_dredir_out(tmp[i]) != -1)
	{
		if (last_child->file_out_trunc != NULL)
		{
			free(last_child->file_out_trunc);
			last_child->file_out_trunc = NULL;
		}
		if (tmp[i + 1] == NULL)
			return (1);
		if (last_child->file_out_app != NULL)
			free(last_child->file_out_app);
		file = rem_quotes(tmp[i + 1]);
		last_child->file_out_app = ft_strdup(file);
		listadd_back(&global->app_file_list_head, listnew(file));
	}
	return (0);
}

int	redir_out_check(char **tmp, int i, t_global *global)
{
	t_child	*last_child;
	char	*file;

	last_child = dlistlast(global->children_head);
	if (is_redir_out(tmp[i]) != -1)
	{
		if (last_child->file_out_app != NULL)
		{
			free(last_child->file_out_app);
			last_child->file_out_app = NULL;
		}
		if (tmp[i + 1] == NULL)
			return (1);
		if (last_child->file_out_trunc != NULL)
			free(last_child->file_out_trunc);
		file = rem_quotes(tmp[i + 1]);
		last_child->file_out_trunc = ft_strdup(file);
		listadd_back(&global->trunc_file_list_head, listnew(file));
	}
	return (0);
}

int	set_files(char **split_input, t_global *global)
{
	char		**tmp;
	int			i;
	t_limiter	lim;

	i = -1;
	while (split_input[++i] != NULL)
	{
		split_input[i] = rem_nl_tab(split_input[i]);
		tmp = split_mod(split_input[i], ' ');
		if (set_dredir_in(tmp, global) == 1)
		{
			ft_free_split(tmp);
			return (1);
		}
		lim.lim = NULL;
		lim.expand = 0;
		dlistadd_back(&global->children_head, dlistnew(NULL, NULL, NULL, lim));
		if (set_redir_in(tmp, global) || set_redirs_out(tmp, global))
		{
			ft_free_split(tmp);
			return (1);
		}
		ft_free_split(tmp);
	}
	return (0);
}
