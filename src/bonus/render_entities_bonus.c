/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_entities_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:28:35 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 13:15:37 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_player(t_game *game)
{
	t_player	*player;
	int			draw_x;
	int			draw_y;

	player = &game->player;
	draw_x = player->location.column * TILE_WIDTH;
	draw_y = player->location.row * TILE_HEIGHT;
	if (player->hit == TRUE)
	{
		put_image(&game->win, game->assets.hit, draw_x, draw_y);
		player->hit = FALSE;
	}
	else
		put_image(&game->win, game->assets.player, draw_x, draw_y);
}

void	draw_enemies(t_game *game)
{
	t_enemy	*enemies;
	int		draw_x;
	int		draw_y;
	int		frame;
	int		i;

	enemies = game->enemies;
	i = 0;
	frame = 0;
	while (i < game->map.enemy_count)
	{
		if (game->enemies[i].alive == TRUE)
		{
			draw_x = enemies[i].location.column * TILE_WIDTH;
			draw_y = enemies[i].location.row * TILE_HEIGHT;
			frame = (game->frames.real_frame / 10 * (i + 1)) % FRAMES;
			put_image(&game->win, game->assets.enemy[frame], draw_x, draw_y);
		}
		i++;
	}
}
