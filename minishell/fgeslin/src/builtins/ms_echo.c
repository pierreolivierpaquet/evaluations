/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:26:29 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/19 12:39:23 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	isflag(const char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	while (str[++i])
	{
		if (str[i] != 'n')
			return (0);
	}
	return (1);
}

int	ms_echo(int argc, char const *argv[], t_mshell *mshell)
{
	int	i;
	int	newline;

	(void)mshell;
	if (argc == 1)
		return (printf("\n"), 0);
	i = 0;
	newline = 1;
	while (++i < argc)
	{
		if (isflag(argv[i]))
			newline = 0;
		else
		{
			printf("%s", argv[i]);
			if (i + 1 < argc)
				printf(" ");
		}
	}
	if (newline)
		printf("\n");
	return (0);
}
