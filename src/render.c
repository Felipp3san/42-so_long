/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:08:46 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 00:55:10 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Limit not inclusive, if 2, results in 0 or 1 */
int random_number(int row, int column, int limit)
{
    double val = sin(row * 12.9898 + column * 78.233) * 43758.5453;
    int rand_num = (int)fabs(val) % limit;

    return rand_num;
}

void	draw_map(t_win *win, char **map, t_map_info *map_info)
{
	int		draw_x;
	int		draw_y;
	int		row;
	int		column;
	int		wall_idx;
	int		floor_idx;
	t_img	*wall[2];
	t_img	*floor[2];

	wall[0] = open_map_tile(win, map, "./textures/wall.xpm");
	wall[1] = open_map_tile(win, map, "./textures/wall_2.xpm");
	floor[0] = open_map_tile(win, map, "./textures/floor.xpm");
	floor[1] = open_map_tile(win, map, "./textures/floor_2.xpm");
	row = 0;
	while (row < map_info->rows)
	{
		column = 0;
		while (column < map_info->columns)
		{
			draw_x = column * 64;
			draw_y = row * 64;
			if (map[row][column] == '1')
			{
				if (row != 0 && row != map_info->rows - 1)
					wall_idx = 0;
				else
					wall_idx = random_number(row, column, 2);
				mlx_put_image_to_window(win->mlx, win->win, wall[wall_idx], draw_x, draw_y);
			}
			else
			{
				floor_idx = random_number(row, column, 2);
				mlx_put_image_to_window(win->mlx, win->win, floor[floor_idx], draw_x, draw_y);
			}
			column++;
		}
		row++;
	}
}

void	draw_objects(t_win *win, char **map, t_map_info *map_info)
{
	int		draw_x;
	int		draw_y;
	int		column;
	int		row;
	int		collectables_idx;
	t_img	*collectables[3];
	t_img	*player;

	player = open_map_tile(win, map, "./textures/player.xpm");
	collectables[0] = open_map_tile(win, map, "./textures/collectable_1.xpm");
	collectables[1] = open_map_tile(win, map, "./textures/collectable_2.xpm");
	collectables[2] = open_map_tile(win, map, "./textures/collectable_3.xpm");
	row = 0;
	while (row < map_info->rows)
	{
		column = 0;
		while (column < map_info->columns)
		{
			draw_x = column * 64;
			draw_y = row * 64;
			if (map[row][column] == 'P')
				mlx_put_image_to_window(win->mlx, win->win, player, draw_x, draw_y);
			else if (map[row][column] == 'C')
			{
				collectables_idx = random_number(row, column, 3);
				mlx_put_image_to_window(win->mlx, win->win, collectables[collectables_idx], draw_x, draw_y);
			}
			column++;
		}
		row++;
	}
}
