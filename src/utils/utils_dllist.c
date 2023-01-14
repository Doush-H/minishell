/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dllist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:08:21 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/16 21:57:55 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	dlistadd_back(t_child **lst, t_child *new_lst)
{
	t_child	*tmp;

	tmp = NULL;
	if (*lst != NULL)
	{
		tmp = dlistlast(*lst);
		new_lst->prev = tmp;
		tmp->next = new_lst;
	}
	else
	{
		*lst = new_lst;
		new_lst->prev = NULL;
	}
}

void	dlistadd_front(t_child **lst, t_child *new_lst)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			new_lst->next = *lst;
			(*lst)->prev = new_lst;
			*lst = new_lst;
			(*lst)->prev = NULL;
		}
		else
		{
			*lst = new_lst;
			new_lst->prev = NULL;
		}
	}
}

void	dlist_rem(t_child **lst, char *str)
{
	t_child	*tmp;

	if (ft_strncmp(str, "front", ft_strlen(str)) == 0)
	{
		if (lst != NULL && *lst != NULL)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			if (*lst != NULL)
				(*lst)->prev = NULL;
			free(tmp);
		}
	}
	else
	{
		if (lst != NULL && *lst != NULL)
		{
			tmp = dlistlast(*lst);
			free(dlistlast(*lst));
			tmp = tmp->prev;
			tmp->next = NULL;
		}
	}
}

t_child	*dlistlast(t_child *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

//f_in = file_in | f_out_t = file_out_trunc | f_out_a = file_out_app
t_child	*dlistnew(char *f_in, char *f_out_t, char *f_out_a, t_limiter limiter)
{
	t_child	*node;

	node = malloc(sizeof(t_child) * 1);
	if (node == NULL)
		return (NULL);
	node->cmd = NULL;
	node->fd_in = -1;
	node->fd_out = -1;
	node->file_in = f_in;
	node->file_out_trunc = f_out_t;
	node->file_out_app = f_out_a;
	node->limiter.lim = limiter.lim;
	node->limiter.expand = limiter.expand;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
