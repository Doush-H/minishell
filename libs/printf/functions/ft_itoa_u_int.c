/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:04:20 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/06 12:42:37 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static unsigned int	high(unsigned int n, unsigned int high);
static unsigned int	get_digits(unsigned int n);
static void			calculate(char *res, unsigned int *n,
						unsigned int size, int *i);

char	*ft_itoa_u_int(unsigned int n)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	if (n < 0)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	size = get_digits(n);
	res = ft_calloc(size + 2, 1);
	if (res == NULL)
		return (res);
	while (i < size)
		calculate(&res[i], &n, size, &i);
	return (res);
}

static unsigned int	high(unsigned int n, unsigned int high)
{
	int	res;

	res = 1;
	while (high--)
		res = res * n;
	return (res);
}

static unsigned int	get_digits(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	calculate(char *res, unsigned int *n, unsigned int size, int *i)
{
	*res = *n / (high(10, size - *i - 1)) + '0';
	*n = *n % high(10, size - *i - 1);
	*i = *i +1;
}
