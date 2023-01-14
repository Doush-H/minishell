/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:23:51 by fbruggem          #+#    #+#             */
/*   Updated: 2022/04/01 14:30:09 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *st, int c, size_t n)
{
	const unsigned char	*s;

	s = st;
	while (n--)
	{
		if (*s == (unsigned char)c)
			return ((void *) s);
		s++;
	}
	return (0);
}
