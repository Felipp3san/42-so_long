/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:25:33 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 12:25:35 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_background(t_game *game)
{
	int	draw_x;
	int	draw_y;
	int	column;
	int	row;

	row = 0;
	while (row < game->map.rows)
	{
		column = 0;
		while (column < game->map.columns)
		{
			draw_x = column * TILE_WIDTH;
			draw_y = row * TILE_HEIGHT;
			if (game->map.map[row][column] == 'E')
				put_image(&game->win,
					game->assets.doors[game->map.door_state], draw_x, draw_y);
			else if (game->map.map[row][column] == '0')
				put_image(&game->win,
					game->assets.floors[get_random_idx(column, row)],
					draw_x, draw_y);
			column++;
		}
		row++;
	}
}

static void	render_walls(t_game *game, int row, int column)
{
	t_map	*map;
	int		draw_x;
	int		draw_y;

	draw_x = column * TILE_WIDTH;
	draw_y = row * TILE_HEIGHT;
	map = &game->map;
	if ((row == 0 && map->map[row + 1][column] != '1')
			|| (row == map->rows - 1 && map->map[row - 1][column] != '1'))
	{
		if (column != 0 && column % 3 == 0)
			put_image(&game->win, game->assets.walls[1], draw_x, draw_y);
		else
			put_image(&game->win, game->assets.walls[0], draw_x, draw_y);
	}
	else if ((column == 0 && map->map[row][column + 1] != '1')
		|| (column == map->columns - 1 && map->map[row][column - 1] != '1'))
	{
		if (row != 0 && row != map->rows - 1 && row % 3 == 0)
			put_image(&game->win, game->assets.walls[1], draw_x, draw_y);
		else
			put_image(&game->win, game->assets.walls[0], draw_x, draw_y);
	}
	else
		put_image(&game->win, game->assets.walls[0], draw_x, draw_y);
}

void	draw_walls(t_game *game)
{
	t_map	*map;
	int		column;
	int		row;

	map = &game->map;
	row = 0;
	while (row < map->rows)
	{
		column = 0;
		while (column < map->columns)
		{
			if (map->map[row][column] == '1')
				render_walls(game, row, column);
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
	int		i;

	map = &game->map;
	i = 0;
	while (i < 4)
	{
		draw_x = 0;
		draw_y = 0;
		if (i % 2 == 1)
			draw_x = (map->columns - 1) * TILE_WIDTH;
		if (i >= 2)
			draw_y = (map->rows - 1) * TILE_HEIGHT;
		frame = (game->frames.real_frame / 10 * (i + 1)) % FRAMES;
		put_image(&game->win, game->assets.torch[frame], draw_x, draw_y);
		i++;
	}
}

void	draw_collectables(t_game *game)
{
	int	draw_x;
	int	draw_y;
	int	column;
	int	row;
	int	frame;

	row = 0;
	while (row < game->map.rows)
	{
		column = 0;
		while (column < game->map.columns)
		{
			draw_x = column * TILE_WIDTH;
			draw_y = row * TILE_HEIGHT;
			if (game->map.map[row][column] == 'C')
			{
				frame = (game->frames.real_frame / 10) % FRAMES;
				put_image(&game->win,
					game->assets.collectables[frame], draw_x, draw_y);
			}
			column++;
		}
		row++;
	}
}
