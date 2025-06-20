/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:33:15 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/20 22:36:33 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	t_player	*player;
	t_map		*map;
	t_point		next;
	t_point		previous;

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
	t_map		*map;
	t_point		next;
	t_point		previous;

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
	t_map		*map;
	t_point		next;
	t_point		previous;

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
	t_map		*map;
	t_point		next;
	t_point		previous;

	map = &game->map;
	player = &game->player;
	previous.row = player->location.row;
	previous.column = player->location.column;
	next.row = previous.row;
	next.column = previous.column + 1;
	if (map->map[next.row] && map->map[next.row][next.column] != '1')
		handle_player_movement(game, &next, &previous);
}
