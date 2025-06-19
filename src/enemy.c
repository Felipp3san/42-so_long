/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:39:13 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/19 15:56:23 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	get_enemy_location(t_map *map, int start_row, int start_column)
{
	t_point	location;
	int		row;
	int		column;

	location.row = 0;
	location.column = 0;
	row = start_row;
	column = start_column;
	while (row < map->rows)
	{
		while (column < map->columns)
		{
			if (map->map[row][column] == 'X')
			{
				location.column = column;
				location.row = row;
				return (location);
			}
			column++;
		}
		column = 0;
		row++;
	}
	return (location);
}

void	init_enemies(t_game *game)
{
	t_enemy	*enemies;
	t_map	*map;
	int		i;
	int		row;
	int		column;

	map = &game->map;
	game->enemies = (t_enemy *) malloc(sizeof(t_enemy) * map->enemies);
	if (!game->enemies)
	{
		clear_program(game);
		exit(EXIT_FAILURE);
	}
	enemies = game->enemies;
	i = 0;
	row = 0;
	column = 0;
	while (i < map->enemies)
	{
		enemies[i].location = get_enemy_location(&game->map, row, column);
		enemies[i].alive = 1;
		row = enemies[i].location.row;
		column = enemies[i].location.column + 1;
		i++;
	}
}

