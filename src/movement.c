/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 03:30:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 04:20:16 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	int	row;
	int	column;

	row = map->player_location.row;
	column = map->player_location.column;
	printf("Player location: Row: %d, Column %d\n", row, column);
	if (map->map[row - 1] && map->map[row - 1][column] != '1') 
	{
		printf("New Player location: Row: %d, Column %d\n", row - 1, column);
		map->map[row - 1][column] = 'P';
		map->map[row][column] = '0';
		map->player_location.row--; 
	}
}

void	move_down(t_map *map)
{
	int	row;
	int	column;

	row = map->player_location.row;
	column = map->player_location.column;
	printf("Player location: Row: %d, Column %d\n", row, column);
	if (map->map[row + 1] && map->map[row + 1][column] != '1') 
	{
		printf("New Player location: Row: %d, Column %d\n", row + 1, column);
		map->map[row + 1][column] = 'P';
		map->map[row][column] = '0';
		map->player_location.row++; 
	}
}

void	move_left(t_map *map)
{
	int	row;
	int	column;

	row = map->player_location.row;
	column = map->player_location.column;
	printf("Player location: Row: %d, Column %d\n", row, column);
	if (map->map[row][column - 1] && map->map[row][column - 1] != '1') 
	{
		printf("New Player location: Row: %d, Column %d\n", row, column - 1);
		map->map[row][column - 1] = 'P';
		map->map[row][column] = '0';
		map->player_location.column--; 
	}
}

void	move_right(t_map *map)
{
	int	row;
	int	column;

	row = map->player_location.row;
	column = map->player_location.column;
	printf("Player location: Row: %d, Column %d\n", row, column);
	if (map->map[row][column + 1] && map->map[row][column + 1] != '1') 
	{
		printf("New Player location: Row: %d, Column %d\n", row, column + 1);
		map->map[row][column + 1] = 'P';
		map->map[row][column] = '0';
		map->player_location.column++; 
	}
}

