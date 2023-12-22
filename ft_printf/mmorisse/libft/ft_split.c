/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorisse <mmorisse@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:10:32 by mmorisse          #+#    #+#             */
/*   Updated: 2023/11/03 18:08:06 by mmorisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_calculmot(char const *s, char c)
{
	t_list	dex;

	ft_bzero(&dex, sizeof(t_list));
	while (s[dex.i] != '\0')
	{
		while (s[dex.i] == c)
			dex.i++;
		if (s[dex.i] != '\0')
			dex.j++;
		while (s[dex.i] != c && s[dex.i] != '\0')
			dex.i++;
	}
	return (dex.j);
}

static size_t	ft_len_mot(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*free_tab(size_t count, char **str_tab)
{
	while (count > 0)
	{
		count--;
		free(str_tab[count]);
	}
	free(str_tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**str_tab;
	t_list	ix;

	ft_bzero(&ix, sizeof(t_list));
	if (!s)
		return (NULL);
	str_tab = ft_calloc((ft_calculmot(s, c) + 1), sizeof(char *));
	if (!str_tab)
		return (NULL);
	while (ix.i < ft_calculmot(s, c))
	{
		while (s[ix.j] && s[ix.j] == c)
			ix.j++;
		str_tab[ix.i] = ft_substr(s, ix.j, ft_len_mot(&s[ix.j], c));
		if (!str_tab[ix.i])
			return (free_tab(ix.i, str_tab));
		while (s[ix.j] && s[ix.j] != c)
			ix.j++;
		ix.i++;
	}
	return (str_tab);
}
