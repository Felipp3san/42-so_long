/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:35:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/21 00:30:49 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_point	get_direction_offset(int dir)
{
	if (dir == UP)
		return ((t_point){-1, 0});
	if (dir == DOWN)
		return ((t_point){1, 0});
	if (dir == LEFT)
		return ((t_point){0, -1});
	return ((t_point){0, 1});
}

static void	enemy_hits_player(t_game *game, t_enemy *enemy)
{
	t_player	*player;

	player = &game->player;
	if (player->lives > 0)
	{
		player->lives--;
		player->hit = TRUE;
	}
	enemy->alive = FALSE;
	if (player->lives == 0)
		game->game_state = LOSE;
}

static void	handle_enemy_movement(t_game *game, int idx)
{
	t_enemy		*enemy;
	t_point		next;
	t_point		offset;
	char		*next_tile;

	enemy = &game->enemies[idx];
	offset = get_direction_offset(enemy->next_direction);
	next.row = enemy->location.row + offset.row;
	next.column = enemy->location.column + offset.column;
	next_tile = &game->map.map[next.row][next.column];
	if (*next_tile != 'E' && *next_tile != '1' && *next_tile != 'C')
	{
		set_tile(&game->map, &enemy->location, '0');
		if (*next_tile == 'P')
		{
			enemy_hits_player(game, enemy);
			if (game->game_state == LOSE)
				return ;
		}
		else
			update_enemy_location(&game->map, enemy, &next);
		game->map.redraw = TRUE;
	}
	update_enemy_direction(enemy);
	return ;
}

void	move_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.enemy_count)
	{
		if (game->enemies[i].alive == TRUE)
			handle_enemy_movement(game, i);
		i++;
	}
}
