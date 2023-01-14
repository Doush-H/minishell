/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:36:03 by fbruggem          #+#    #+#             */
/*   Updated: 2022/04/01 14:28:36 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	return (c == ' ' || c == '\a' || c == '\b' || c == '\f'
		|| c == '\n' || c == '\r' || c == '\t' || c == '\v' );
}

static int	get_value(const char *str, int mul)
{
	long	temp;
	long	res;

	res = 0;
	while (*str >= '0' && *str <= '9' )
	{
		temp = res;
		res = res * 10 + *str - '0';
		if (temp > res)
		{
			if (mul == -1)
				return (0);
			return (-1);
		}
		str++;
	}
	return (res * mul);
}

int	ft_atoi(const char *str)
{
	int		mul;

	mul = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mul *= -1;
		str++;
	}
	return (get_value(str, mul));
}
