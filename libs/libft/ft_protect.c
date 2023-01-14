/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:12:41 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/07 16:50:24 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	del_ptr(void **ptr, int n);

int	ft_protect(int n, ...)
{
	va_list	list;
	void	**ptr;
	int		i;

	ptr = ft_calloc(n, sizeof(void *));
	if (!ptr)
		return (-1);
	va_start(list, n);
	i = 0;
	while (i < n)
		ptr[i++] = va_arg(list, void *);
	va_end(list);
	i = 0;
	while (i < n)
		if (!ptr[i++])
			return (del_ptr(ptr, n));
	free(ptr);
	return (0);
}

int	del_ptr(void **ptr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(ptr[i++]);
	free(ptr);
	return (-1);
}
