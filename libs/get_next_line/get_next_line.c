/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:41:03 by fbruggem          #+#    #+#             */
/*   Updated: 2022/04/24 13:08:42 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem;
	int			read_res;
	char		*temp;
	char		*res;

	read_res = 1;
	temp = malloc(BUFFER_SIZE + 1);
	temp[0] = '\0';
	while (!char_exists(temp) && read_res != 0)
	{
		read_res = read(fd, temp, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(mem);
			free(temp);
			return (NULL);
		}
		temp[read_res] = '\0';
		if (read_res != 0)
				mem = stringjoin(mem, temp);
	}
	free(temp);
	res = get_line(mem);
	mem = rem_line(mem);
	return (res);
}

char	*get_line(char *mem)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = NULL;
	if (!mem)
		return (NULL);
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	if (mem[i] == '\n')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	while (j <= i)
	{
		res[j] = mem[j];
		j++;
	}
	if (mem[i -1] == '\n')
		res[i] = '\0';
	return (res);
}

char	*rem_line(char *mem)
{
	char	*res;
	int		i;
	int		j;

	if (!mem)
		return (NULL);
	i = strlength(mem, '\n') + 1;
	if (mem[i] == '\0' || mem[i - 1] == '\0')
	{
		free(mem);
		return (NULL);
	}
	j = 0;
	res = malloc(strlength(mem, '\0') - strlength(mem, '\n') + 1);
	if (res == NULL)
	{
		free(mem);
		return (NULL);
	}
	while (mem[i] != '\0')
		res[j++] = mem[i++];
	res[j] = '\0';
	free(mem);
	return (res);
}
