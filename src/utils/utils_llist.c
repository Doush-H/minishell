/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_llist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:05:15 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/11 15:55:10 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	listadd_back(t_file_node **lst, t_file_node *new_lst)
{
	t_file_node	*tmp;

	tmp = NULL;
	if (*lst != NULL)
	{
		tmp = listlast(*lst);
		tmp->next = new_lst;
	}
	else
	{
		*lst = new_lst;
	}
}

void	listadd_front(t_file_node **lst, t_file_node *new_lst)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			new_lst->next = *lst;
			*lst = new_lst;
		}
		else
		{
			*lst = new_lst;
		}
	}
}

void	list_rem(t_file_node **lst, char *str)
{
	t_file_node	*tmp;

	if (ft_strncmp(str, "front", ft_strlen(str)) == 0)
	{
		if (lst != NULL && *lst != NULL)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			free(tmp);
		}
	}
	else
	{
		if (lst != NULL && *lst != NULL)
		{
			tmp = listlast(*lst);
			free(listlast(*lst));
			tmp->next = NULL;
		}
	}
}

t_file_node	*listlast(t_file_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_file_node	*listnew(char *file)
{
	t_file_node	*node;

	node = malloc(sizeof(t_file_node) * 1);
	if (node == NULL)
		return (NULL);
	node->path = file;
	node->next = NULL;
	return (node);
}
