/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:26:52 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/21 11:16:07 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "children.h"

int		open_tmp_read(void);
int		perror_int(char *str);
int		exec_child_single_builtin(t_global *global, t_child *child);
void	single_cmd(t_global *global, t_child *tmp, int fd_cur0);
void	multiple_cmd(t_global *global, t_child *tmp, int fd_c[], int fd_tmp[]);

void	children_exec(t_global *global)
{
	int		fd_current[2];
	int		fd_temp[2];
	t_child	*tmp;

	fd_current[0] = -1;
	fd_current[1] = -1;
	tmp = global->children_head;
	while (tmp != NULL)
	{
		single_cmd(global, tmp, fd_current[0]);
		multiple_cmd(global, tmp, fd_current, fd_temp);
		tmp = tmp->next;
	}
	signal(SIGINT, SIG_IGN);
	while (wait(&g_exit_code) != -1 || errno != ECHILD)
		continue ;
}

void	single_cmd(t_global *global, t_child *tmp, int fd_cur0)
{
	if (tmp->limiter.lim != NULL)
		limiter_exec(tmp, global->env);
	else if (cmd_count(global) <= 1)
	{
		if (tmp->cmd == NULL || tmp->cmd[0] == NULL)
			return ;
		if (builtin_is_cmd(tmp->cmd, global->env))
			exec_child_single_builtin(global, tmp);
		else
		{
			setup_pipes_last(fd_cur0, tmp);
			child_exec(tmp, global, -1);
			if (fd_cur0 != -1)
				close(fd_cur0);
		}
	}
}

void	multiple_cmd(t_global *global, t_child *tmp, int fd_c[], int fd_tmp[])
{
	if (tmp->cmd == NULL || tmp->cmd[0] == NULL)
		return ;
	if (tmp->limiter.lim == NULL
		&& tmp->next != NULL && cmd_count(global) > 1)
	{
		pipe(fd_tmp);
		setup_pipes_normal(&fd_c[0], &fd_c[1], fd_tmp[1], tmp);
		child_exec(tmp, global, fd_tmp[0]);
		if (tmp->prev != NULL)
			close(fd_c[0]);
		fd_c[0] = fd_tmp[0];
		close(fd_c[1]);
	}
	else if (cmd_count(global) > 1 && tmp->limiter.lim == NULL)
	{
		setup_pipes_last(fd_c[0], tmp);
		child_exec(tmp, global, -1);
		if (fd_c[0] != -1)
			close(fd_c[0]);
	}
}

int	exec_child_single_builtin(t_global *global, t_child *child)
{
	int		infd_tmp;
	int		outfd_tmp;

	infd_tmp = dup(STDIN_FILENO);
	outfd_tmp = dup(STDOUT_FILENO);
	if (child->fd_in != -1 && dup2_close(child->fd_in, STDIN_FILENO))
		return (perror_int("Error fd_in"));
	if (child->fd_out != -1 && dup2_close(child->fd_out, STDOUT_FILENO))
		return (perror_int("Error fd_out"));
	if (child->file_in && child_exec_set_file_in_fd(child->file_in))
		return (perror_int("Error file_in"));
	if (child->prev && child->prev->limiter.lim != NULL
		&& child->limiter.lim == NULL
		&& dup2_close(open_tmp_read(), STDIN_FILENO))
		return (perror_int("Error here_doc"));
	if (child->file_out_trunc
		&& child_exec_set_file_out_trunc_fd(child->file_out_trunc))
		return (perror_int("Error file_out_trunc"));
	if (child->file_out_app && child_exec_ofd(child->file_out_app))
		return (perror_int("Error file_out_app"));
	dup2(infd_tmp, STDIN_FILENO);
	builtin_exec(child, global);
	dup2_close(infd_tmp, STDIN_FILENO);
	dup2_close(outfd_tmp, STDOUT_FILENO);
	return (0);
}

int	perror_int(char *str)
{
	if (str)
		perror(str);
	return (1);
}
