/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:25:31 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/16 20:37:03 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILDREN_H
# define CHILDREN_H

# include "../../minishell.h"
# include "../builtin/builtin.h"

int		child_exec(t_child *child, t_global *global, int free_pipe);
int		limiter_exec(t_child *child, char **env);
char	*child_where( char *cmd, char **env);
char	**get_paths(char **env);
char	*get_cmd(char *str);

// Child_exec_utils
int		child_exec_set_file_in_fd(char *file);
int		child_exec_set_file_out_trunc_fd(char *file);
int		child_exec_ofd(char *file);
int		dup2_close(int fd, int fd2);
void	perror_exit(char *str);

// Children_exec_utils
int		cmd_count(t_global *global);
void	setup_pipes_normal(int *fd_current0, int *fd_current1,
			int fd_temp, t_child *child);
void	setup_pipes_last(int fd_current0, t_child *child);
#endif