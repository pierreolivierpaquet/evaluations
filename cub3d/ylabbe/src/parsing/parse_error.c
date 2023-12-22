/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:54:27 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/26 16:54:28 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_parse	*ft_check_error(char **data, t_parse *parse)
{
	int	i;

	i = 0;
	while (data && data[i])
	{
		if (ft_file(data[i]) == 1 && parse->file_north == 1)
			parse->file_north = ft_check_file(data[i]);
		else if (ft_file(data[i]) == 2 && parse->file_south == 1)
			parse->file_south = ft_check_file(data[i]);
		else if (ft_file(data[i]) == 3 && parse->file_west == 1)
			parse->file_west = ft_check_file(data[i]);
		else if (ft_file(data[i]) == 4 && parse->file_east == 1)
			parse->file_east = ft_check_file(data[i]);
		else if (ft_file(data[i]) == 5 && parse->file_floor == 1)
			parse->file_floor = validate_rgb_color(data[i], 0);
		else if (ft_file(data[i]) == 6 && parse->file_ceiling == 1)
			parse->file_ceiling = validate_rgb_color(data[i], 0);
		i++;
	}
	return (parse);
}

t_parse	*ft_get_error(t_parse *parse, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_file(tab[i]) == 1)
			parse->file_north += 1;
		else if (ft_file(tab[i]) == 2)
			parse->file_south += 1;
		else if (ft_file(tab[i]) == 3)
			parse->file_west += 1;
		else if (ft_file(tab[i]) == 4)
			parse->file_east += 1;
		else if (ft_file(tab[i]) == 5)
			parse->file_floor += 1;
		else if (ft_file(tab[i]) == 6)
			parse->file_ceiling += 1;
		else if (ft_file(tab[i]) == 7)
			parse->file_wrong_line += 1;
		i++;
	}
	return (parse);
}

int	ft_error(t_parse *parse)
{
	if (parse->file_north != 1 || parse->file_south != 1
		|| parse->file_west != 1 || parse->file_east != 1
		|| parse->file_ceiling != 1 || parse->file_floor != 1
		|| parse->file_wrong_line != 0 || parse->file_too_much != 6)
	{
		printf("Error\nColor or/and texture problem\n");
		return (1);
	}
	if (parse->map_wg_player != 0 || parse->map_wg_player_number != 0
		|| parse->map_wg_space != 0 || parse->map_wg_zero != 0
		|| parse->map_wg_character != 0 || parse->map_wg_corner != 0)
	{
		printf("Error\nMap problem\n");
		return (1);
	}
	return (0);
}
