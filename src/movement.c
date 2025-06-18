/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 03:30:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 13:34:36 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map, t_player *player)
{
	int	row;
	int	column;

	row = player->location.row;
	column = player->location.column;
	if (map->map[row - 1] && map->map[row - 1][column] != '1') 
	{
		ft_printf("New Player location: Row: %d, Column %d\n", row - 1, column);
		map->map[row - 1][column] = 'P';
		map->map[row][column] = '0';
		player->location.row--; 
		map->redraw = 1;
	}
}

void	move_down(t_map *map, t_player *player)
{
	int	row;
	int	column;

	row = player->location.row;
	column = player->location.column;
	printf("Player location: Row: %d, Column %d\n", row, column);
	if (map->map[row + 1] && map->map[row + 1][column] != '1') 
	{
		printf("New Player location: Row: %d, Column %d\n", row + 1, column);
		map->map[row + 1][column] = 'P';
		map->map[row][column] = '0';
		player->location.row++; 
		map->redraw = 1;
	}
}

void	move_left(t_map *map, t_player *player)
{
	int	row;
	int	column;

	row = player->location.row;
	column = player->location.column;
	printf("Player location: Row: %d, Column %d\n", row, column);
	if (map->map[row][column - 1] && map->map[row][column - 1] != '1') 
	{
		printf("New Player location: Row: %d, Column %d\n", row, column - 1);
		map->map[row][column - 1] = 'P';
		map->map[row][column] = '0';
		player->location.column--; 
		map->redraw = 1;
	}
}

void	move_right(t_map *map, t_player *player)
{
	int	row;
	int	column;

	row = player->location.row;
	column = player->location.column;
	printf("Player location: Row: %d, Column %d\n", row, column);
	if (map->map[row][column + 1] && map->map[row][column + 1] != '1') 
	{
		printf("New Player location: Row: %d, Column %d\n", row, column + 1);
		map->map[row][column + 1] = 'P';
		map->map[row][column] = '0';
		player->location.column++; 
		map->redraw = 1;
	}
}

