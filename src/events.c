/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:07:37 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 04:04:50 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_key_press(int key_code, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (key_code == XK_Escape)
		exit(1);
	if (key_code == XK_W || key_code == XK_w)
	{
		ft_printf("Move up\n");
		move_up(game->map);
	}
	if (key_code == XK_A || key_code == XK_a)
	{
		ft_printf("Move down\n");
		move_left(game->map);
	}
	if (key_code == XK_S || key_code == XK_s)
	{
		ft_printf("Move left\n");
		move_down(game->map);
	}
	if (key_code == XK_D || key_code == XK_d)
	{
		ft_printf("Move right\n");
		move_right(game->map);
	}
	return (0);
}
