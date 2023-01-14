/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:27:12 by fbruggem          #+#    #+#             */
/*   Updated: 2022/04/02 15:22:27 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1x, const void *s2x, size_t n)
{
	const char	*s1;
	const char	*s2;

	s1 = s1x;
	s2 = s2x;
	while (n && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		return ((unsigned char) *s1 - (unsigned char) *s2);
	return (0);
}
