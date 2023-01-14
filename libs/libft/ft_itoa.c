/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:06:41 by fbruggem          #+#    #+#             */
/*   Updated: 2022/03/31 14:09:09 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	high(int n, int high);
static int	get_digits(int n);
static void	calculate(char *res, int *n, int size, int *i);

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = get_digits(n);
	res = ft_calloc(size + 2, 1);
	if (res == NULL)
		return (res);
	if (n < 0)
	{
		n *= -1;
		size++;
		i++;
		res[0] = '-';
	}	
	while (i < size)
		calculate(&res[i], &n, size, &i);
	return (res);
}

static int	high(int n, int high)
{
	int	res;

	res = 1;
	while (high--)
		res = res * n;
	return (res);
}

static int	get_digits(int n)
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

static void	calculate(char *res, int *n, int size, int *i)
{
	*res = *n / (high(10, size - *i - 1)) + '0';
	*n = *n % high(10, size - *i - 1);
	*i = *i +1;
}
