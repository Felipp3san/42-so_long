/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_entities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:00:02 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/19 16:03:00 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game)
{
	int			draw_x;
	int			draw_y;

	draw_x = game->player.location.column * TILE_WIDTH;
	draw_y = game->player.location.row * TILE_HEIGHT;
	put_image(&game->win, game->assets.player, draw_x, draw_y);
}

void	draw_enemies(t_game *game)
{
	t_assets	*assets;
	t_enemy		*enemies;
	t_map		*map;
	int			draw_x;
	int			draw_y;
	int			frame; 
	int			i;

	map = &game->map;
	assets = &game->assets;
	enemies = game->enemies;
	i = 0;
	while (i < map->enemies)
	{
		draw_x = enemies[i].location.column * TILE_WIDTH;
		draw_y = enemies[i].location.row * TILE_HEIGHT;
		frame = (game->frames.real_frame / 10 * (i + 1)) % FRAMES;
		put_image(&game->win, assets->enemy[frame], draw_x, draw_y);
		i++;
	}
}
