/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 03:30:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 21:16:32 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_interaction(t_game *game, t_point *next, t_point *previous)
{
	t_map		*map;
	t_player	*player;
	char		*next_tile;

	map = &game->map;
	player = &game->player;
	next_tile = &map->map[next->row][next->column];
	if (*next_tile == 'E' && map->door_state == CLOSED)
		return ;
	if (*next_tile == 'X' && player->lives > 0)
		player->lives--;
	if (*next_tile == 'C')
	{
		player->collectables++; 
		if (player->collectables == map->collectables)
			map->door_state = OPEN;
	}
	*next_tile = 'P';
	map->map[previous->row][previous->column] = '0';
	map->redraw = 1;
	player->move_count++;
	player->location.row = next->row; 
	player->location.column = next->column; 
	ft_printf("Move count: %d\n", player->move_count);
}

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
		handle_interaction(game, &next, &previous);
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
		handle_interaction(game, &next, &previous);
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
		handle_interaction(game, &next, &previous);
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
		handle_interaction(game, &next, &previous);
}

