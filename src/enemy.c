/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:39:13 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/21 01:13:20 by fde-alme         ###   ########.fr       */
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

t_enemy	*find_enemy(t_game *game, t_point *location)
{
	int	i;

	i = 0;
	while (i < game->map.enemy_count)
	{
		if (game->enemies[i].location.row == location->row
			&& game->enemies[i].location.column == location->column)
			return (&game->enemies[i]);
		i++;
	}
	return (NULL);
}

void	update_enemy_location(t_map *map, t_enemy *enemy, t_point *next)
{
	set_tile(map, next, 'X');
	enemy->location = *next;
}

void	update_enemy_direction(t_enemy *enemy)
{
	if (enemy->next_direction == RIGHT)
		enemy->next_direction = UP;
	else
		enemy->next_direction++;
}

void	init_enemies(t_game *game)
{
	t_enemy	*enemies;
	int		i;
	int		row;
	int		column;

	game->enemies = (t_enemy *) malloc(sizeof(t_enemy) * game->map.enemy_count);
	if (!game->enemies)
	{
		clear_program(game);
		exit(EXIT_FAILURE);
	}
	enemies = game->enemies;
	i = 0;
	row = 0;
	column = 0;
	while (i < game->map.enemy_count)
	{
		enemies[i].location = get_enemy_location(&game->map, row, column);
		enemies[i].alive = TRUE;
		enemies[i].next_direction = i % 4;
		row = enemies[i].location.row;
		column = enemies[i].location.column + 1;
		i++;
	}
}
