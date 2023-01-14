/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u_long.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:23:41 by fbruggem          #+#    #+#             */
/*   Updated: 2022/04/19 10:18:25 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void				tf_write_int_recusive(unsigned long nbr,
							unsigned long base_nbr, char *base);
static unsigned long	ft_check_if_valid_base(char *base,
							unsigned long base_nbr);

void	ft_putnbr_base_u_long(unsigned long nbr, char *base)
{
	unsigned long	base_nbr;

	base_nbr = 0;
	while (base[base_nbr] != '\0')
		base_nbr++;
	if (ft_check_if_valid_base(base, base_nbr))
	{
		if (nbr == 0)
			write(1, &base[0], 1);
		else
			tf_write_int_recusive(nbr, base_nbr, base);
	}
}

static void	tf_write_int_recusive(unsigned long nbr,
						unsigned long base_nbr, char *base)
{
	unsigned long	current_nbr;

	if (nbr != 0)
	{
		current_nbr = (nbr % base_nbr);
		tf_write_int_recusive((nbr - nbr % base_nbr) / base_nbr,
			base_nbr, base);
		write(1, &base[current_nbr], 1);
	}
}

static unsigned long	ft_check_if_valid_base(char *base,
						unsigned long base_nbr)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	if (base_nbr < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i +1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
