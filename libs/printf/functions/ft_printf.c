/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:32:15 by fbruggem          #+#    #+#             */
/*   Updated: 2022/04/18 09:18:14 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_print_value(char identifier, va_list list, int *counter);

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		counter;

	counter = 0;
	va_start(list, str);
	while (*str != '\0')
	{
		if (*str == '%' && str[1] != '\0')
		{
			ft_print_value(str[1], list, &counter);
			str += 2;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			counter++;
			str++;
		}
	}
	va_end(list);
	return (counter);
}

void	ft_print_value(char identifier, va_list list, int *counter)
{
	if (identifier == 'c')
		*counter += ft_print_char(va_arg(list, int));
	else if (identifier == 's')
		*counter += ft_print_string(va_arg(list, char *));
	else if (identifier == 'i')
		*counter += ft_print_decimal(va_arg(list, int));
	else if (identifier == 'd')
		*counter += ft_print_decimal(va_arg(list, int));
	else if (identifier == 'p')
		*counter += ft_print_pointer(va_arg(list, unsigned long));
	else if (identifier == 'u')
		*counter += ft_print_decimal_u(va_arg(list, unsigned int));
	else if (identifier == 'x')
		*counter += ft_print_hex(va_arg(list, unsigned long),
				"0123456789abcdef");
	else if (identifier == 'X')
		*counter += ft_print_hex(va_arg(list, unsigned long),
				"0123456789ABCDEF");
	else if (identifier == '%')
	{
		ft_putchar_fd('%', 1);
		*counter = *counter + 1;
	}
}
