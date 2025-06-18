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
				break;
			}
			column++;
		}
		row++;
	}
	return (location);
}

void	init_player(t_player *player, t_map *map)
{
	player->location = get_player_location(map);
	player->lives = MAX_LIVES;
	player->collectables = 0;
	player->move_count = 0;
}

