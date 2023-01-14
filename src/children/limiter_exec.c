/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:36:11 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/21 13:31:27 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "children.h"

char	*set_vars_here_doc(char *str, char **env);
int		open_tmp(void);
void	print_res_free(char *res, char *read_line);
char	*rem_quotes(char *str);
char	*set_vars(char *str, char **env);

void	here_doc_ginal(int sig)
{
	if (sig == SIGINT)
		close(STDIN_FILENO);
}

void	setup_here_doc_signal(int *fd_in_cpy)
{
	signal(SIGINT, &here_doc_ginal);
	*fd_in_cpy = dup(STDIN_FILENO);
}

int	limiter_exec(t_child *child, char **env)
{
	char	*res;
	char	*tmp2;
	char	*read_line;
	int		fd_in_cpy;

	setup_here_doc_signal(&fd_in_cpy);
	res = NULL;
	read_line = readline("here_doc> ");
	while (read_line && ft_strncmp(read_line, child->limiter.lim,
			ft_strlen(child->limiter.lim) + 1) != 0)
	{
		if (child->limiter.expand == 1)
		{
			tmp2 = read_line;
			read_line = set_vars_here_doc(read_line, env);
			free(tmp2);
		}
		read_line = ft_strjoin_free(read_line, "\n");
		res = ft_strjoin_free(res, read_line);
		free(read_line);
		read_line = readline("here_doc> ");
	}
	print_res_free(res, read_line);
	dup2_close(fd_in_cpy, STDIN_FILENO);
	return (0);
}

int	open_tmp(void)
{
	int	fd;

	fd = open("./.tmp_minishell", O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		return (-1);
	return (fd);
}

void	print_res_free(char *res, char *read_line)
{
	int	fd;

	fd = open_tmp();
	ft_putstr_fd(res, fd);
	close(fd);
	ft_protect(3, read_line, res, NULL);
}
