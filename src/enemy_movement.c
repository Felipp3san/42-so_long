/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:08:38 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/19 18:52:54 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	get_direction_offset(int dir)
{
	if (dir == UP)
		return ((t_point){-1, 0});
	if (dir == DOWN)
		return ((t_point){1, 0});
	if (dir == LEFT)
		return ((t_point){0, -1});
	return ((t_point){0, 1});
}

void	handle_movement(t_game *game, int idx)
{
	t_enemy		*enemy;
	t_point		next;
	t_point		offset;
	t_map		*map;
	char		*next_tile;

	map = &game->map;
	enemy = &game->enemies[idx];
	offset = get_direction_offset(enemy->next_direction);
	next.row = enemy->location.row + offset.row;
	next.column = enemy->location.column + offset.column;
	next_tile = &map->map[next.row][next.column];
	if (*next_tile != 'E' && *next_tile != '1' && *next_tile != 'C')
	{
		map->map[enemy->location.row][enemy->location.column] = '0';
		map->map[next.row][next.column] = 'X';
		map->redraw = 1;
		enemy->location = next;
	}
	if (enemy->next_direction == 3)
		enemy->next_direction = 0;
	else
		enemy->next_direction++;
	return ;
}

void	movement_enemies(t_game *game)
{
	t_map		*map;
	int			i;

	map = &game->map;
	i = 0;
	while (i < map->enemy_count)
	{
		handle_movement(game, i);
		i++;
	}
}
