/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:12:57 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 12:30:41 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	redraw_map(t_game *game)
{
	draw_background(game);
	draw_player(game);
	draw_hearts_ui(game);
	draw_movements_ui(game);
	game->map.redraw = FALSE;
}

static void	update_frames(t_game *game)
{
	t_frames	*frames;

	frames = &game->frames;
	frames->frame_count++;
	if (frames->frame_count >= MAX_FRAME)
		frames->frame_count = 0;
	frames->real_frame = frames->frame_count / ANIMATION_SPEED;
	if (frames->real_frame != frames->last_frame)
	{
		frames->last_frame = frames->real_frame;
		draw_enemies(game);
		draw_torches(game);
		draw_collectables(game);
	}
	if (game->frames.frame_count % MOVEMENT_SPEED == 0)
		move_enemies(game);
}

static void	handle_game_end(t_game *game)
{
	if (game->game_state == LOSE)
		draw_lose(game);
	else
		draw_win(game);
}

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (game->game_state != RUNNING)
		handle_game_end(game);
	else
	{
		update_frames(game);
		if (game->map.redraw == TRUE)
			redraw_map(game);
	}
	return (0);
}
