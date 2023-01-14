/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:14:50 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/22 23:39:20 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "src/builtin/builtin.h"

int	g_exit_code = 0;

void	setup_termios_new(t_global *global)
{
	struct termios	term;

	tcgetattr(0, &global->old_termios);
	term = global->old_termios;
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_code = 1;
		return ;
	}
}

void	free_node_files(t_global *global)
{
	file_node_free(global->app_file_list_head);
	file_node_free(global->trunc_file_list_head);
}

int	main(int argc, char **argv, char **env)
{
	t_global			global;
	struct sigaction	sa;

	if (!argv || argc != 1)
		return (1);
	setup_termios_new(&global);
	sa.sa_handler = &handle_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	set_to_default(&global, env);
	while (1)
	{
		if (input_read(&global) == 0)
		{
			open_files(global.app_file_list_head, global.trunc_file_list_head);
			children_exec(&global);
			sigaction(SIGINT, &sa, NULL);
		}
		children_free(global.children_head);
		free_node_files(&global);
		free(global.input);
	}
	return (0);
}
