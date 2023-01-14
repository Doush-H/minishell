/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:31:24 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/15 00:00:46 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/**
 * @brief gives back the current absolute path
 * 
 * @return int 
 */
int	builtin_pwd(void)
{
	char	res[PATH_MAX];

	getcwd(res, PATH_MAX);
	printf("%s\n", res);
	if (close(STDIN_FILENO) < 0 && close(STDOUT_FILENO) < 0)
		return (1);
	return (0);
}
