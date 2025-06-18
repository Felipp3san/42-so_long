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
	t_assets	*assets;
	int			draw_x;
	int			draw_y;
	int			i;

	i = 0;
	assets = game->assets;
	while (i < MAX_LIVES)
	{
		draw_x = i * TILE_WIDTH;
		draw_y = (game->map->rows) * TILE_HEIGHT;
		if (i < game->player->lives)
			put_image(game->win, assets->hearts[FILLED_HEART], draw_x, draw_y);
		else
			put_image(game->win, assets->hearts[EMPTY_HEART], draw_x, draw_y);
		i++;
	}
}

void	draw_movements(t_game *game)
{
	t_assets	*assets;
	int			draw_x;
	int			draw_y;
	int			i;
	int			moves;
	int			nb_digits;

	i = 0;
	assets = game->assets;
	moves = game->player->move_count;
	nb_digits = ft_nbdigits_base(moves, 10);
	while (i < nb_digits)
	{
		draw_x = (game->map->columns - (i + 1)) * TILE_WIDTH;
		draw_y = (game->map->rows) * TILE_HEIGHT;
		put_image(game->win, assets->numbers[moves % 10], draw_x, draw_y);
		moves = moves / 10;
		i++;
	}
}
