/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:17:57 by fgeslin           #+#    #+#             */
/*   Updated: 2023/05/16 11:17:57 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define READLINE_LIBRARY
# include "../lib/libft/headers/libft.h"
# include "../lib/readline/includes/readline.h"
# include "../lib/readline/includes/history.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define MAX_PATH_LENGTH 1024
# define MAX_ARGS 128
# define TMPFILE "/tmp/heredoc"
# define WHTSPACES "\t\n\v\f\r \0"

typedef const char **	t_mat;

typedef struct s_cmd
{
	int		argc;
	char	**argv;
	int		redirc;
	char	**redirs;
	int		pipe[2];
}	t_cmd;

typedef struct s_cmdtab
{
	int		cmdc;
	t_cmd	*cmdv;
}	t_cmdtab;

typedef struct s_mshell
{
	unsigned char	exit_status;
	char			**env;
}	t_mshell;

typedef struct s_redirections
{
	int		input_fd;
	int		output_fd;
	char	*input_file;
	char	*output_file;
	char	*append_file;
	char	*delimiter;
}				t_redirections;

//Unit tests, remove before pushing project for grading
char		**ms_parse_input(char *input);
void		ms_free_args(char **args);
int			ms_execute(char **args);
int			test_main(void);

//matrix
int			get_matrixlen(const char **matrix);
char		**expand_matrix(const char **matrix, char *new_line);
char		**shrink_matrix(const char **matrix, const char *to_remove);
char		**dup_matrix(const char **matrix);
void		print_matrix(const char **matrix);
void		print_sortedmatrix(char const **matrix);
void		free_matrix(char **matrix);

//env
char		*ms_getenv(char const *var, char const **env);
void		init_env(char const *env[], t_mshell *mshell);
int			update_envp(const char *str, t_mshell *mshell);
int			is_valid_envp(const char *str, int n);

//pipes
int			exec_pipeline(t_cmdtab *cmd_tab, t_mshell *mshell);
int			exec_cmd(t_cmd cmd, t_mshell *mshell);

//signals
void		signal_handler(int signo);
void		new_prompt_signal(void);

//parsing
t_cmdtab	*tokenize(char const *prompt, t_mshell *mshell);
char		**cmd_split(char const *s);
char		*arg_quotes(char const *str, int len, t_mshell *mshell);
//parsing utils
char		*ft_append(char *s1, char const *s2, int n);
int			nextquote(char const *s);
int			smartcount(char const *s, char const *sep, int trim_sep);
int			ft_perror(int count, ...);

//freeing
void		free_cmdtab(t_cmdtab *cmd_tab);

//redirections
int			call_redirections(t_cmd *cmd);
int			open_output_file(char *filename, int flags, mode_t mode);
void		handle_input_redirection(char **argv, int *argc, char **input_file);
void		handle_output_file(char **argv, int *argc, char **file, int index);
void		handle_single_output_redirection(char **argv,
				int *argc, char **file, char *operator);
void		handle_output_redirection(char **argv,
				int *argc, char **output_file, char **append_file);
void		redir_error(void);

#endif