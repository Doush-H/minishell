/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:23:46 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/17 15:25:59 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	open_files(t_file_node *app_files, t_file_node *trunc_files)
{
	int	fd;

	while (app_files != NULL)
	{
		fd = open(app_files->path, O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		close(fd);
		app_files = app_files->next;
	}
	while (trunc_files != NULL)
	{
		fd = open(trunc_files->path, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		close(fd);
		trunc_files = trunc_files->next;
	}
	return (0);
}
