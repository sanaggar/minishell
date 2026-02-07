/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:45:05 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/18 06:19:58 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_data
{
	char	**env;
	int		fd_in;
	int		fd_out;
	char	*pwd;
	int		redir;

	pid_t	parent_pid;
	char	*str;
	char	*delimiter;
	int		j;
	int		k;
	char	*temp_file;
	int		fd;
	char	*input_line;
	int		file_contents_length;
	char	*arg_error;
	char	*file_contents;
	char	*temp;

	char	*new_command;
	char	*old_command;
	int		length;
	char	*delimiter_start;
	char	*delimiter_end;
	int		i_memory;
	int		heredoc_i;
	int		p;
	int		status;
	int		succes_redir;
	char	*current_input;

	int		i_cleaner;
	char	*var_value;
	char	*cdpath;
	int		flag_denied_perm;
	int		index_i;
	int		index;
}				t_data;

extern int		g_signal;

int				envlen(char **env);
void			free_env(char **env);
char			**dup_env(char **env);
void			close_fds(t_data *data);

int				parser_start(char *str, t_data *data);
void			quote_len(char **str, int *i, char quote);
char			**input_split(char *str);

int				handle_basic(char *clean_input, t_data *data, int piped);
void			handle_echo(char **args, t_data *data);
void			handle_cd(char **args, t_data *data);
void			handle_unset(char **inputs, t_data *data);
void			exit_pipe(t_data *data);
void			free_inputs(char **inputs);
void			close_fds(t_data *data);
void			dup_close(int *oldfd, t_data *data);

void			free_variable(t_data *data, char *tmp, char **input_ad);
void			ft_var_value(t_data *data);
char			**export_env(char **old_env, char *export);
char			**ft_add_str_to_tab(char **tab2, char *new_str);
void			handle_env(char **inputs, char **env, t_data *data);

int				change_pwd(t_data *data, char *input);
void			handle_pwd(t_data *data);

int				is_relative(char *str);
char			**gen_paths(int index, t_data *data, char *input);
int				check_exec(char **inputs, t_data *data);
void			handle_exec(char **args, t_data *data);
void			handle_sig(int sig);

void			replace_var(char *new_var, t_data *data, int index);
int				var_index(char *name, t_data *data);
int				print_export(char **env);
int				check_export(char *str, t_data *data);
char			**copy_export_env(char **env);
void			handle_export(char **args, t_data *data);
void			export_env_handle_env(t_data *data, char **inputs, int i);
void			sentence_handle_export(t_data *data, char **inputs, int i);

int				handle_pipe(char *input1, char *input2, t_data *data);
int				parser_delegator(char *input, t_data *data, int piped);
int				parser_error(char *str, t_data *data);
void			parser_variable(char **input_address, int *i, t_data *data);
int				parser_redir(char **input_address, t_data *data);
int				handle_redir(char **input_address, int i, t_data *data);
int				redir_delimiter(char *str, char **input, int i, t_data *data);
void			remove_redir_input(char **input_address, int i, int j);
int				get_name_len(char *str);
char			*get_filename(char *str, int *j);
void			input_copy(char *dst, char *src);
char			*input_cleaner(char *str, t_data *data);
void			copy_newsplit(char *src, char *dst, char quote);
void			escape_char(char **dst, char **src);
void			should_escape(int *i, char *str);

void			sig_exec_init(t_data *data);
void			sig_init(t_data *data);
void			sig_init_main(void);
void			sig_ignore(void);
void			sig_init_main(void);
void			sig_reset(void);

void			error_sentence(char *str, int status, t_data *data);
void			error_sentence_exec(char *input, int status, t_data *data);
void			handle_exit(char **inputs, t_data *data);

int				create_line(char **str, char **line);
int				check_nl(char *str);
int				last_line(char **str, char **line);
int				mega_error(char *str1, char *str2);

void			redir_from(char *str, int i, char **input, t_data *data);
void			redir_to_append(char *str, int i, char **input, t_data *data);
void			sigint_handler(int sig);
void			sig_reset(void);

int				redir_error(char *str, int i);
int				redir_error1(char *str, int i);
int				redir_error2(char *str, int i);
int				redir_error3(char *str, int i);
int				redir_error4(char *str, int i);
int				redir_error5(char *str, int i);
int				redir_error_pipe(char *str, int i);
int				redir_error_pipe1(char *str, int i);
int				redir_error_semi(char *str, int i);
int				redir_error_semi1(char *str, int i);
int				redir_error_space(char *str, int i);
int				if_semi(char *str);
int				else_redir_error(char **input, int *i, t_data *data);
int				else_redir_error2(char **input, int *i, t_data *data);
void			else_error_redir(t_data *data);
int				ambiguous_error(char *str, t_data *data);

#endif
