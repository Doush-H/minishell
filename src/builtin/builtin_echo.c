/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:08:56 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/19 18:01:47 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	builtin_echo_print_words(char **text);

/**
 * @brief Prints the given parameters already extended with env
 * 
 * @param cmd as {"echo", "VALUE", ... }
 * @return int || 0 = SUCCESS | 1 = ERROR
 */
int	builtin_echo(t_child *child)
{
	int	j;
	int	n;

	n = 0;
	j = 1;
	if (close(STDIN_FILENO) < 0)
		return (1);
	if (!child || !child->cmd)
		return (1);
	while (child->cmd[j] && ft_strncmp(child->cmd[j], "-n", 3) == 0)
	{
		n = 1;
		j++;
	}
	builtin_echo_print_words(&child->cmd[j]);
	if (n == 0)
		ft_printf("\n");
	if (close(STDOUT_FILENO) < 0)
		return (1);
	return (0);
}

static int	builtin_echo_print_words(char **text)
{
	int	i;
	int	j;

	j = 0;
	while (text[j])
	{
		i = 0;
		while (text[j][i])
		{
			ft_printf("%c", text[j][i]);
			i++;
		}
		if (text[j + 1])
			ft_printf(" ");
		j++;
	}
	return (0);
}
