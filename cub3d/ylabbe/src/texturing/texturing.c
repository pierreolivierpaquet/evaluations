/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:09:49 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/28 17:09:51 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	load_bitmap(t_game *info, int idx, char *path)
{
	t_img	*simg;

	simg = &(info->map->img[idx]);
	simg->img = mlx_xpm_file_to_image(info->mlx, path, &(simg->wid),
			&(simg->hei));
	simg->addr = mlx_get_data_addr(simg->img, &(simg->bpp), &(simg->len),
			&(simg->endian));
}
