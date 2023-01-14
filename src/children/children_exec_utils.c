/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_exec_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:59:39 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/15 01:00:54 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "children.h"

int		cmd_count(t_global *global);
void	setup_pipes_normal(int *fd_current0, int *fd_current1,
			int fd_temp, t_child *child);
void	setup_pipes_last(int fd_current0, t_child *child);

int	cmd_count(t_global *global)
{
	int		count;
	t_child	*tmp;

	count = 0;
	tmp = global->children_head;
	while (tmp != NULL)
	{
		if (tmp->cmd != NULL && tmp->limiter.lim == NULL)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	setup_pipes_normal(int *fd_current0, int *fd_current1,
			int fd_temp, t_child *child)
{
	*fd_current1 = fd_temp;
	child->fd_in = *fd_current0;
	child->fd_out = *fd_current1;
}

void	setup_pipes_last(int fd_current0, t_child *child)
{
	child->fd_in = fd_current0;
	child->fd_out = -1;
}
