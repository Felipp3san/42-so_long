/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 03:30:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 18:12:21 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_interaction(t_map *map, t_player *player, t_point *next, t_point *previous)
{
	if (map->map[next->row][next->column] == 'E' && map->door_closed == 1)
		return ;
	if (map->map[next->row][next->column] == 'X' && player->lives > 0)
		player->lives--;
	if (map->map[next->row][next->column] == 'C')
	{
		player->collectables++; 
		if (player->collectables == map->collectables)
			map->door_closed = 0;
	}
	map->map[next->row][next->column] = 'P';
	map->map[previous->row][previous->column] = '0';
	map->redraw = 1;
	player->move_count++;
	player->location.row = next->row; 
	player->location.column = next->column; 
}

void	move_up(t_map *map, t_player *player)
{
	t_point	next;
	t_point	previous;

	previous.row = player->location.row;
	previous.column = player->location.column;
	next.row = previous.row - 1;
	next.column = previous.column;
	if (map->map[next.row] && map->map[next.row][next.column] != '1') 
		handle_interaction(map, player, &next, &previous);
}

void	move_down(t_map *map, t_player *player)
{
	t_point	next;
	t_point	previous;

	previous.row = player->location.row;
	previous.column = player->location.column;
	next.row = previous.row + 1;
	next.column = previous.column;
	if (map->map[next.row] && map->map[next.row][next.column] != '1') 
		handle_interaction(map, player, &next, &previous);
}

void	move_left(t_map *map, t_player *player)
{
	t_point	next;
	t_point	previous;

	previous.row = player->location.row;
	previous.column = player->location.column;
	next.row = previous.row;
	next.column = previous.column - 1;
	if (map->map[next.row] && map->map[next.row][next.column] != '1') 
		handle_interaction(map, player, &next, &previous);
}

void	move_right(t_map *map, t_player *player)
{
	t_point	next;
	t_point	previous;

	previous.row = player->location.row;
	previous.column = player->location.column;
	next.row = previous.row;
	next.column = previous.column + 1;
	if (map->map[next.row] && map->map[next.row][next.column] != '1') 
		handle_interaction(map, player, &next, &previous);
}

