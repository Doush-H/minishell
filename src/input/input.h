/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:23:08 by fbruggem          #+#    #+#             */
/*   Updated: 2022/07/19 17:29:43 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "../../minishell.h"
# include "../utils/utils.h"

typedef struct s_set_vars
{
	char	*ret_str;
	int		i;
	int		j;
	char	*value;
	char	*var_name;
	int		quotes;
}				t_set_vars;

int		input_parse(t_global *global);
char	*rem_redirs(char *old_input);
char	*rem_nl_tab(char *str);

//input_add_spaces
int		is_valid_redir(const char *str, int i);
int		len_with_spaces(const char *str);
char	*add_spaces(char *str);

//dredir_in
char	*rem_dredir_in(char *str);
int		is_dredir_in_split(char **str);
int		is_dredir_in(char *str);

//dredir_out
int		is_dredir_out(char *str);
char	*rem_dredir_out(char *str);
int		is_dredir_out_split(char **str);

//redir_in
int		is_redir_in(char *str);
char	*rem_redir_in(char *str);
int		is_redir_in_split(char **str);

//redir_out
int		is_redir_out(char *str);
char	*rem_redir_out(char *str);
int		is_redir_out_split(char **str);

//set_vars
char	*set_vars(char *str, char **env);
int		get_expanded_len(char *str, char **env);
char	*get_var_name(char *str);

//utils
void	print_split(char **str);
void	print_children(t_child *list);
int		split_len(char **str);
char	**split_dup(char **str);

//input_rem_quotes
char	*rem_quotes(char *str);
char	**input_rem_quotes(char **input);
char	*remove_first_character(char *str);

//input_expand_rem_redir
char	*rem_redirs(char *old_input);
char	**input_clear_redirs(char **input);
char	**input_expand(char **input, char **env);

//set_files
int		set_files(char **split_input, t_global *global);

//clear_and_set_cmds
void	clear_and_set_cmds(char **split_input, t_global *global);

#endif