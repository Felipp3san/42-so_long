/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:31:48 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/21 00:25:12 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_gets_collectable(t_game *game)
{
	t_player	*player;
	t_map		*map;

	player = &game->player;
	map = &game->map;
	player->collectables++;
	if (player->collectables == map->collectable_count)
		map->door_state = OPEN;
}

void	handle_player_movement(t_game *game, t_point *next, t_point *previous)
{
	t_map	*map;
	char	*next_tile;

	map = &game->map;
	next_tile = &map->map[next->row][next->column];
	if (*next_tile == 'E' && map->door_state == CLOSED)
		return ;
	else if (*next_tile == 'E' && map->door_state == OPEN)
	{
		game->player.move_count++;
		ft_printf("Move count: %d\n", game->player.move_count);
		game->game_state = WIN;
		return ;
	}
	if (*next_tile == 'C')
		player_gets_collectable(game);
	update_player_location(game, next, previous);
	ft_printf("Move count: %d\n", game->player.move_count);
	map->redraw = 1;
}
