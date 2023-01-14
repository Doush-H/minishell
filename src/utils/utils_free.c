/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:15:12 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/21 13:32:16 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	children_free(t_child *head)
{
	t_child	*temp;

	while (head != NULL)
	{
		temp = head->next;
		if (head->cmd)
			ft_free_split(head->cmd);
		free(head->file_in);
		free(head->file_out_trunc);
		free(head->file_out_app);
		free(head->limiter.lim);
		free(head);
		head = temp;
	}
	return (0);
}

int	file_node_free(t_file_node *node)
{
	t_file_node	*temp;

	while (node)
	{
		temp = node->next;
		free(node->path);
		free(node);
		node = temp;
	}
	return (0);
}

int	global_free(t_global *global)
{
	children_free(global->children_head);
	ft_free_split(global->env);
	free(global->input);
	file_node_free(global->trunc_file_list_head);
	file_node_free(global->app_file_list_head);
	return (0);
}
