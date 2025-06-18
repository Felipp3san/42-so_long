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

	row = 0;
	while (row < game->map.rows)
	{
		column = 0;
		while (column < game->map.columns)
		{
			draw_x = column * TILE_WIDTH;
			draw_y = row * TILE_HEIGHT;
			if (game->map.map[row][column] == '0')
				put_image(&game->win, game->assets.floor, draw_x, draw_y);
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
