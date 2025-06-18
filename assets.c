/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:54:06 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 00:55:51 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*open_map_tile(t_win *win, char **map, char *path)
{
	t_img	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	if (!img)
	{
		perror("mlx_xpm_file_to_image failed");
		clear_program(win, map);
		exit(1);
	}
	return (img);
}

void	init_tile_images(t_tile_images *group)
{
	group->variants = ;
	group->count = ;
}

void	init_assets(t_game_assets	*assets)
{
	assets->walls = init_tile_images();
}
