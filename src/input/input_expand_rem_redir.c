/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_expand_rem_redir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:37:16 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/20 18:01:05 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	**input_expand(char **input, char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	if (input == NULL)
		return (NULL);
	tmp = malloc((split_len(input) + 1) * sizeof(char *));
	while (input[i] != NULL)
	{
		tmp[i] = set_vars(input[i], env);
		i++;
	}
	tmp[i] = NULL;
	ft_free_split(input);
	return (tmp);
}

char	**input_clear_redirs(char **input)
{
	int		i;
	char	**tmp;

	i = 0;
	if (input == NULL)
		return (NULL);
	tmp = malloc((split_len(input) + 1) * sizeof(char *));
	while (input[i] != NULL)
	{
		tmp[i] = rem_redirs(input[i]);
		i++;
	}
	tmp[i] = NULL;
	free(input);
	return (tmp);
}

char	*rem_redirs(char *old_input)
{
	char	*ret;

	ret = NULL;
	ret = rem_dredir_out(old_input);
	ret = rem_dredir_in(ret);
	ret = rem_redir_in(ret);
	ret = rem_redir_out(ret);
	return (ret);
}
