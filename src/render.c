/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:08:46 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 13:37:10 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_win *win, t_map *map, t_assets *assets)
{
	int		draw_x;
	int		draw_y;
	int		column;
	int		row;

	row = 0;
	while (row < map->rows)
	{
		column = 0;
		while (column < map->columns)
		{
			draw_x = column * TILE_WIDTH;
			draw_y = row * TILE_HEIGHT;
			if (map->map[row][column] == '1')
				mlx_put_image_to_window(win->mlx, win->win, 
							assets->wall, draw_x, draw_y);
			else
				mlx_put_image_to_window(win->mlx, win->win, 
							assets->floor, draw_x, draw_y);
			column++;
		}
		row++;
	}
}

void	draw_objects(t_win *win, t_map *map, t_assets *assets)
{
	int		draw_x;
	int		draw_y;
	int		column;
	int		row;

	row = 0;
	while (row < map->rows)
	{
		column = 0;
		while (column < map->columns)
		{
			draw_x = column * TILE_WIDTH;
			draw_y = row * TILE_HEIGHT;
			if (map->map[row][column] == 'C')
				mlx_put_image_to_window(win->mlx, win->win, 
							assets->collectable, draw_x, draw_y);
			column++;
		}
		row++;
	}
}

void	draw_player(t_win *win, t_assets *assets, t_player *player)
{
	int		draw_x;
	int		draw_y;

	draw_x = player->location.column * TILE_WIDTH;
	draw_y = player->location.row * TILE_HEIGHT;
	mlx_put_image_to_window(win->mlx, win->win, assets->player, draw_x, draw_y);
}
