/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_entities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:00:02 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/21 00:29:35 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game)
{
	t_player	*player;
	int			draw_x;
	int			draw_y;

	player = &game->player;
	draw_x = player->location.column * TILE_WIDTH;
	draw_y = player->location.row * TILE_HEIGHT;
	put_image(&game->win, game->assets.player, draw_x, draw_y);
}
