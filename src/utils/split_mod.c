/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:38:23 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/07/19 18:01:37 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*skip_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str != NULL && *str == c && *str != '\0')
	{
		str++;
		i++;
		if (c == '|' && i > 1)
			return (NULL);
	}
	return (str);
}

char	*copy_word(char *str, char c)
{
	int		i;
	char	*ret_str;
	int		size;

	i = 0;
	size = get_len(str, c);
	ret_str = malloc(size + 1);
	while (i < size)
	{
		ret_str[i++] = *str;
		str++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}

char	*skip_word(char *str, char c)
{
	int		i;
	int		size;

	i = 0;
	size = get_len(str, c);
	while (i < size)
	{
		str++;
		i++;
	}
	return (str);
}

char	**split_mod(char *str, char c)
{
	char	**ret;
	int		i;
	int		size;

	if (str == NULL)
		return (NULL);
	size = word_count(str, c);
	ret = malloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		str = skip_char(str, c);
		if (*str != '\0')
		{
			ret[i] = copy_word(str, c);
			str = skip_word(str, c);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

//------------------DEBUG AND TESTING-----------------

// void	print_split(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != NULL)
// 	{
// 		if (i != 0)
// 			printf(" ");
// 		printf("<%s>", str[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

// int main ()
// {
// 	char *test1 = "echo hello | cat -e";
// 	char *test2 = "echo \"hello   a\" | cat -e";
// 	char *test3 = "echo \"hello   a |\" cat -e";
// 	char *test4 = "echo \'hello   a |\' cat -e";
// 	char *test5 = "echo hello|cat -e";
// 	char **str = split_mod(test1, '|');
// 	print_split(str);
// 	str = split_mod(test2, '|');
// 	print_split(str);
// 	str = split_mod(test3, '|');
// 	print_split(str);
// 	str = split_mod(test4, '|');
// 	print_split(str);
// 	str = split_mod(test5, '|');
// 	print_split(str);
// }