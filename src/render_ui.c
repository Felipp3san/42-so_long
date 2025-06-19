/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:12:28 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 16:29:17 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_hearts(t_game *game)
{
	int			draw_x;
	int			draw_y;
	int			i;

	i = 0;
	while (i < MAX_LIVES)
	{
		draw_x = i * TILE_WIDTH;
		draw_y = (game->map.rows) * TILE_HEIGHT;
		if (i < game->player.lives)
			put_image(&game->win, game->assets.hearts[FILLED], draw_x, draw_y);
		else
			put_image(&game->win, game->assets.hearts[EMPTY], draw_x, draw_y);
		i++;
	}
}

void	draw_movements(t_game *game)
{
	int			draw_x;
	int			draw_y;
	int			nb_digits;
	int			moves;
	int			i;

	i = 0;
	moves = game->player.move_count;
	nb_digits = ft_nbdigits_base(moves, 10);
	while (i < nb_digits)
	{
		draw_x = (game->map.columns - (i + 1)) * TILE_WIDTH;
		draw_y = (game->map.rows) * TILE_HEIGHT;
		put_image(&game->win, game->assets.numbers[moves % 10], draw_x, draw_y);
		moves = moves / 10;
		i++;
	}
}
