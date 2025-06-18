/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:07:37 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 17:44:04 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_key_press(int key_code, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (key_code == XK_Escape)
	{
		clear_program(game);
		exit(0);
	}
	if (key_code == XK_W || key_code == XK_w)
		move_up(game->map, game->player);
	if (key_code == XK_A || key_code == XK_a)
		move_left(game->map, game->player);
	if (key_code == XK_S || key_code == XK_s)
		move_down(game->map, game->player);
	if (key_code == XK_D || key_code == XK_d)
		move_right(game->map, game->player);
	return (0);
}
