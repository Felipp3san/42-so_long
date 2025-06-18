/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_entities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:00:02 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 22:52:45 by fde-alme         ###   ########.fr       */
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
	int			draw_x;
	int			draw_y;
	int			column;
	int			row;
	int			frame; 

	assets = &game->assets;
	frame = (game->frames.real_frame / 10) % ENEMY_FRAMES;
	row = 0;
	while (row < game->map.rows)
	{
		column = 0;
		while (column < game->map.columns)
		{
			draw_x = column * TILE_WIDTH;
			draw_y = row * TILE_HEIGHT;
			if (game->map.map[row][column] == 'X')
				put_image(&game->win, assets->enemy[frame], draw_x, draw_y);
			column++;
		}
		row++;
	}
}
