/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:54:33 by ylabbe            #+#    #+#             */
/*   Updated: 2023/06/02 18:30:21 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_parsing_second(t_parse *parse, char **data, char **map)
{
	parse = ft_check_error(data, parse);
	parse = ft_map(parse, map);
	map = ft_free_tab(map);
	data = ft_free_tab(data);
	if (ft_error(parse) == 1)
	{
		free(parse);
		return (1);
	}
	free(parse);
	return (0);
}

int	ft_error_easy(t_parse *parse)
{
	if (parse->file_too_much != 6)
	{
		printf("Error\nI can't\n");
		return (1);
	}
	return (0);
}

void	ft_free_data_s(char **data)
{
	char	**current;

	current = data;
	if (data == NULL)
		return ;
	while (*current != NULL)
	{
		free(*current);
		current++;
	}
	free(data);
}

int	ft_parsing(char **tab)
{
	t_parse	*parse;
	char	**data;
	char	**map;

	parse = malloc(sizeof(t_parse));
	if (!parse)
		return (0);
	data = malloc(sizeof(char *) * 9);
	if (!data)
	{
		free(parse);
		return (0);
	}
	parse = init_struct(parse);
	parse = ft_get_error(parse, tab);
	data = ft_add_value_to_data(tab, parse, data, 0);
	if (ft_error_easy(parse) == 1)
	{
		ft_free_data_s(data);
		free(parse);
		return (1);
	}
	map = ft_add_to_map(tab);
	return (ft_parsing_second(parse, data, map));
}
