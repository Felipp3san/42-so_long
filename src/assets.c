/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:56:13 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 00:56:20 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_assets(t_win *win, t_assets *assets)
{
	if (assets->wall)
		mlx_destroy_image(win->mlx, assets->wall);
	if (assets->player)
		mlx_destroy_image(win->mlx, assets->player);
	if (assets->floor)
		mlx_destroy_image(win->mlx, assets->floor);
	if (assets->collectable)
		mlx_destroy_image(win->mlx, assets->collectable);
}

t_img	*open_map_tile(t_win *win, t_map *map, t_assets *assets,  char *path)
{
	t_img	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	if (!img)
	{
		perror("mlx_xpm_file_to_image failed");
		clear_program(win, map, assets);
		exit(1);
	}
	return (img);
}

void	init_assets(t_win *win, t_map *map, t_assets *assets)
{
	assets->wall = 
		open_map_tile(win, map, assets, "./textures/wall.xpm");
	assets->player = 
		open_map_tile(win, map, assets, "./textures/player.xpm");
	assets->floor = 
		open_map_tile(win, map, assets, "./textures/floor.xpm");
	assets->collectable = 
		open_map_tile(win, map, assets, "./textures/collectable_1.xpm");
}
