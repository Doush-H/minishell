/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printNumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:09:23 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/06 12:42:50 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_print_decimal(int nbr)
{
	char	*str;
	int		res;

	res = 0;
	str = ft_itoa(nbr);
	if (str)
	{
		ft_putstr_fd(str, 1);
		res = ft_strlen(str);
		free(str);
	}
	return (res);
}

int	ft_print_decimal_u(unsigned int nbr)
{
	char	*str;
	int		res;

	res = 0;
	str = ft_itoa_u_int(nbr);
	if (str)
	{
		ft_putstr_fd(str, 1);
		res = ft_strlen(str);
		free(str);
	}	
	return (res);
}

int	ft_print_pointer(unsigned long nbr)
{
	int	res;

	res = 0;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_putnbr_base_u_long(nbr, "0123456789abcdef");
	if (nbr == 0)
		res += 1;
	while (nbr)
	{
		nbr = nbr / 16;
		res++;
	}
	res += 2;
	return (res);
}

int	ft_print_hex(unsigned long nbr, char *base)
{
	int				res;
	unsigned int	temp;

	res = 0;
	ft_putnbr_base_u(nbr, base);
	temp = nbr;
	if (temp == 0)
		res += 1;
	while (temp)
	{
		temp = temp / 16;
		res++;
	}
	return (res);
}
