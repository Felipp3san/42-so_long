/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:31:48 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 13:17:13 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_hits_enemy(t_game *game, t_point *location)
{
	t_enemy		*enemy;
	t_player	*player;

	player = &game->player;
	enemy = find_enemy(game, location);
	if (!enemy)
		return ;
	enemy->alive = 0;
	if (player->lives > 0)
	{
		player->lives--;
		player->hit = TRUE;
	}
	if (player->lives == 0)
		game->game_state = LOSE;
}

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
		game->game_state = WIN;
		return ;
	}
	if (*next_tile == 'X')
		player_hits_enemy(game, next);
	if (*next_tile == 'C')
		player_gets_collectable(game);
	update_player_location(game, next, previous);
	map->redraw = 1;
}
