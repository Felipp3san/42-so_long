/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:08:46 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 22:54:14 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_game *game)
{
	int		draw_x;
	int		draw_y;
	int		column;
	int		row;
	int		idx;
	int		hash;

	row = 0;
	while (row < game->map.rows)
	{
		column = 0;
		while (column < game->map.columns)
		{
			draw_x = column * TILE_WIDTH;
			draw_y = row * TILE_HEIGHT;
			if (game->map.map[row][column] == '0')
			{
				hash = (column * 13 + row * 31) % 100;
				if (hash < 5)
					idx = 2;       // rare
				else if (hash < 20)
					idx = 1;       // less rare
				else
					idx = 0;       // common
				put_image(&game->win, game->assets.floors[idx], draw_x, draw_y);
			}
			column++;
		}
		row++;
	}
}

void	draw_walls(t_game *game)
{
	t_map	*map;
	int		draw_x;
	int		draw_y;
	int		column;
	int		row;

	map = &game->map;
	row = 0;
	while (row < map->rows)
	{
		column = 0;
		while (column < map->columns)
		{
			draw_x = column * TILE_WIDTH;
			draw_y = row * TILE_HEIGHT;
			if (map->map[row][column] == '1')
				put_image(&game->win, game->assets.wall, draw_x, draw_y);
			column++;
		}
		row++;
	}
}

void	draw_torches(t_game *game)
{
	t_map	*map;
	int		draw_x;
	int		draw_y;
	int		frame; 

	map = &game->map;
	draw_y = 0;
	draw_x = (map->columns - 1) * TILE_WIDTH;
	frame = (game->frames.real_frame / 10) % FRAMES;
	put_image(&game->win, game->assets.torch[frame], 0, draw_y);
	frame = (game->frames.real_frame / 20) % FRAMES;
	put_image(&game->win, game->assets.torch[frame], draw_x, draw_y);
	draw_y = (map->rows - 1) * TILE_HEIGHT;
	frame = (game->frames.real_frame / 30) % FRAMES;
	put_image(&game->win, game->assets.torch[frame], 0, draw_y);
	frame = (game->frames.real_frame / 40) % FRAMES;
	put_image(&game->win, game->assets.torch[frame], draw_x, draw_y);
}

void	draw_objects(t_game *game)
{
	t_assets	*assets;
	t_map		*map;
	int			draw_x;
	int			draw_y;
	int			column;
	int			row;

	map = &game->map;
	assets = &game->assets;
	row = 0;
	while (row < map->rows)
	{
		column = 0;
		while (column < map->columns)
		{
			draw_x = column * TILE_WIDTH;
			draw_y = row * TILE_HEIGHT;
			if (map->map[row][column] == 'C')
				put_image(&game->win, assets->collectables[0], draw_x, draw_y);
			else if (game->map.map[row][column] == 'E')
				put_image(&game->win, assets->doors[map->door_state], draw_x, draw_y);
			column++;
		}
		row++;
	}
}
