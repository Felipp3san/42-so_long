/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:12:57 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/21 01:47:27 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	redraw_map(t_game *game)
{
	draw_background(game);
	draw_player(game);
	draw_torch(game);
	draw_collectable(game);
	game->map.redraw = FALSE;
}

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (game->game_state != RUNNING)
		draw_win(game);
	else
	{
		if (game->map.redraw == TRUE)
			redraw_map(game);
	}
	return (0);
}
