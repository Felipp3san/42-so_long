/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:25:09 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 12:25:11 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_game *game)
{
	t_player	*player;
	t_point		next;
	t_point		previous;
	t_map		*map;

	map = &game->map;
	player = &game->player;
	previous.row = player->location.row;
	previous.column = player->location.column;
	next.row = previous.row - 1;
	next.column = previous.column;
	if (map->map[next.row] && map->map[next.row][next.column] != '1')
		handle_player_movement(game, &next, &previous);
}

void	move_down(t_game *game)
{
	t_player	*player;
	t_point		next;
	t_point		previous;
	t_map		*map;

	map = &game->map;
	player = &game->player;
	previous.row = player->location.row;
	previous.column = player->location.column;
	next.row = previous.row + 1;
	next.column = previous.column;
	if (map->map[next.row] && map->map[next.row][next.column] != '1')
		handle_player_movement(game, &next, &previous);
}

void	move_left(t_game *game)
{
	t_player	*player;
	t_point		next;
	t_point		previous;
	t_map		*map;

	map = &game->map;
	player = &game->player;
	previous.row = player->location.row;
	previous.column = player->location.column;
	next.row = previous.row;
	next.column = previous.column - 1;
	if (map->map[next.row] && map->map[next.row][next.column] != '1')
		handle_player_movement(game, &next, &previous);
}

void	move_right(t_game *game)
{
	t_player	*player;
	t_point		next;
	t_point		previous;
	t_map		*map;

	map = &game->map;
	player = &game->player;
	previous.row = player->location.row;
	previous.column = player->location.column;
	next.row = previous.row;
	next.column = previous.column + 1;
	if (map->map[next.row] && map->map[next.row][next.column] != '1')
		handle_player_movement(game, &next, &previous);
}
