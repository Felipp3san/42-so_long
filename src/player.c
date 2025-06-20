/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:03:05 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 15:33:35 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_location(t_game *game, t_point *next, t_point *previous)
{
	set_tile(&game->map, previous, '0');
	set_tile(&game->map, next, 'P');
	game->player.location.row = next->row;
	game->player.location.column = next->column;
	game->player.move_count++;
}

t_point	get_player_location(t_map *map)
{
	t_point	location;
	int		row;
	int		column;

	location.row = 0;
	location.column = 0;
	row = 0;
	while (row < map->rows)
	{
		column = 0;
		while (column < map->columns)
		{
			if (map->map[row][column] == 'P')
			{
				location.column = column;
				location.row = row;
				return (location);
			}
			column++;
		}
		row++;
	}
	return (location);
}

void	check_player_death(t_game *game)
{
	if (game->player.lives == 0)
		game->game_state = LOSE;
}

void	init_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	player->location = get_player_location(&game->map);
	player->lives = MAX_LIVES;
	player->collectables = 0;
	player->move_count = 0;
}
