/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:15:45 by fbruggem          #+#    #+#             */
/*   Updated: 2023/01/14 14:08:04 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libs/libs.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <termios.h>
# include "readline/readline.h"
# include "readline/history.h"
# include <sys/errno.h>
# include <sys/wait.h>

extern int	g_exit_code;

typedef struct s_limiter
{
	char	*lim;
	int		expand;
}				t_limiter;

typedef struct s_file_node
{
	char				*path;
	struct s_file_node	*next;
}				t_file_node;

typedef struct s_child
{
	char			**cmd;
	int				fd_in;
	int				fd_out;
	char			*file_in;
	char			*file_out_trunc;
	char			*file_out_app;
	t_limiter		limiter;
	struct s_child	*next;
	struct s_child	*prev;

}				t_child;

typedef struct s_global
{
	int				ex_status;
	char			**env;
	struct termios	old_termios;
	char			*input;
	t_child			*children_head;
	t_file_node		*trunc_file_list_head;
	t_file_node		*app_file_list_head;
}				t_global;

int		set_to_default(t_global	*global, char **env);

int		input_read(t_global *global);

int		open_files(t_file_node *app_files, t_file_node *trunc_files);

void	children_exec(t_global *global);

// Built In
int		builtin_exec(t_child *child, t_global *global);

void	handle_sigint(int sig);

#endif