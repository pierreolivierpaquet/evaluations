/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:23:01 by fgeslin           #+#    #+#             */
/*   Updated: 2023/06/02 13:51:00 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/ms_builtins.h"

static char	*expand_cmd(char *name, char *path)
{
	char	**paths;
	char	*temp_path;
	int		len;
	int		i;

	if (ft_strchr(name, '/') || !path)
		return (name);
	paths = ft_split((const char *)path, ':');
	len = 0;
	while (paths[len])
		len++;
	i = 0;
	while (i < len)
	{
		temp_path = ft_strdup(paths[i]);
		temp_path = ft_append(temp_path, "/", 2);
		temp_path = ft_append(temp_path, name, ft_strlen(name) + 1);
		if (access(temp_path, F_OK) == 0)
			return (free_matrix(paths), temp_path);
		free(temp_path);
		i++;
	}
	return (free_matrix(paths), NULL);
}

int	exec_cmd(t_cmd cmd, t_mshell *mshell)
{
	int		exit_status;

	if (!cmd.argv[0])
		return (0);
	exit_status = call_builtin(cmd.argc, (t_mat)cmd.argv, mshell);
	if (exit_status > -1)
		return (exit_status);
	exit_status = execve(expand_cmd(cmd.argv[0], ms_getenv("PATH",
					(t_mat)mshell->env)), cmd.argv, mshell->env);
	if (exit_status > -1)
		return (exit_status);
	ft_perror(2, "command not found:", cmd.argv[0]);
	return (127);
}
