/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 09:04:18 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/06 13:07:04 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_decimal(int nbr);
int		ft_print_decimal_u(unsigned int nbr);
int		ft_print_pointer(unsigned long nbr);
int		ft_print_hex(unsigned long nbr, char *base);
char	*ft_itoa_u_long(unsigned long n);
void	ft_putnbr_base_u(unsigned int nbr, char *base);
void	ft_putnbr_base_u_long(unsigned long nbr, char *base);
char	*ft_itoa_u_int(unsigned int n);

#endif
