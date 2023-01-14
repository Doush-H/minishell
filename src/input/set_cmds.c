/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:22:37 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/19 17:33:00 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	clear_and_set_cmds(char **split_input, t_global *global)
{
	int		i;
	t_child	*tmp;

	i = 0;
	tmp = global->children_head;
	while (tmp != NULL)
	{
		if (tmp->limiter.lim == NULL)
		{
			split_input[i] = rem_nl_tab(split_input[i]);
			tmp->cmd = split_mod(split_input[i], ' ');
			tmp->cmd = input_expand(tmp->cmd, global->env);
			tmp->cmd = input_rem_quotes(tmp->cmd);
			i++;
		}
		tmp = tmp->next;
	}
}
