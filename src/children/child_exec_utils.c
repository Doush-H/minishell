/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:36:24 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/16 10:10:25 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "children.h"

int	child_exec_set_file_in_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "open failed: file name %s\n", file);
		return (1);
	}
	if (dup2_close(fd, STDIN_FILENO) < 0)
	{
		fprintf(stderr, "dup2 in file in failed\n");
		return (1);
	}
	return (0);
}

int	child_exec_set_file_out_trunc_fd(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0 || dup2_close(fd, STDOUT_FILENO))
		return (1);
	return (0);
}

// child_exec_set_file_out_app_fd
int	child_exec_ofd(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0 || dup2_close(fd, STDOUT_FILENO))
		return (1);
	return (0);
}

int	dup2_close(int fd, int fd2)
{
	if (dup2(fd, fd2) < 0)
		return (1);
	if (close(fd) < 0)
		return (1);
	return (0);
}

void	perror_exit(char *str)
{
	perror(str);
	exit(1);
}
