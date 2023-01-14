/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:06:07 by fbruggem          #+#    #+#             */
/*   Updated: 2022/03/31 13:55:20 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;

	mem = (malloc(count * size));
	if (mem == NULL)
		return (NULL);
	mem = ft_memset(mem, '\0', size * count);
	return ((void *)mem);
}
