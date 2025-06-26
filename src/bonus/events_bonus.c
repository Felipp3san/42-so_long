/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:27:49 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 13:15:23 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	ft_printf("Closing game...\n");
	clear_program(game);
	exit(EXIT_SUCCESS);
}

int	on_key_press(int key_code, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (key_code == XK_Escape)
	{
		clear_program(game);
		exit(EXIT_SUCCESS);
	}
	if (game->game_state == RUNNING)
	{
		if (key_code == XK_W || key_code == XK_w)
			move_up(game);
		if (key_code == XK_A || key_code == XK_a)
			move_left(game);
		if (key_code == XK_S || key_code == XK_s)
			move_down(game);
		if (key_code == XK_D || key_code == XK_d)
			move_right(game);
	}
	return (0);
}
