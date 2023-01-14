/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileexists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:05:25 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/10 10:30:08 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_fileexists(char *path)
{
	int	fd;

	fd = open(path, 0);
	if (read(fd, NULL, 0) == -1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
