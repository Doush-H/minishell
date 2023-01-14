/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:41:44 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/06 13:08:42 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_line(char *mem);
size_t	strlength(const char *s, char end);
char	*stringjoin(char const *s1, char const *s2);
char	*stringdup(const char *s1, size_t nbr);
char	*rem_line(char *mem);
int		char_exists(char *s);

#endif