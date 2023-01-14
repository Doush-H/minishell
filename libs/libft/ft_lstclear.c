/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:58:11 by fbruggem          #+#    #+#             */
/*   Updated: 2022/03/31 14:09:17 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*mem;

	mem = NULL;
	while (*lst != NULL)
	{
		(*del)((*lst)->content);
		mem = (*lst)->next;
		free(*lst);
		*lst = mem;
	}
}
