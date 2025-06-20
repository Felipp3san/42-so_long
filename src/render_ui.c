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

void	draw_hearts_ui(t_game *game)
{
	int	draw_x;
	int	draw_y;
	int	i;

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

void	draw_movements_ui(t_game *game)
{
	int	draw_x;
	int	draw_y;
	int	nb_digits;
	int	moves;
	int	i;

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

void	draw_end(t_game *game)
{
	int		draw_x;
	int		draw_y;
	int		lose_length;

	lose_length = 8;
	draw_x = (game->map.columns - lose_length) / 2 * TILE_WIDTH;
	draw_y = game->map.rows / 2 * TILE_HEIGHT;
	
	mlx_clear_window(game->win.mlx, game->win.win);
	put_image(&game->win, game->assets.letters[0], draw_x, draw_y);
	draw_x = draw_x + TILE_WIDTH;
	put_image(&game->win, game->assets.letters[1], draw_x, draw_y);
	draw_x = draw_x + TILE_WIDTH;
	put_image(&game->win, game->assets.letters[2], draw_x, draw_y);
	draw_x = draw_x + TILE_WIDTH * 2;
	put_image(&game->win, game->assets.letters[3], draw_x, draw_y);
	draw_x = draw_x + TILE_WIDTH;
	put_image(&game->win, game->assets.letters[1], draw_x, draw_y);
	draw_x = draw_x + TILE_WIDTH;
	put_image(&game->win, game->assets.letters[4], draw_x, draw_y);
	draw_x = draw_x + TILE_WIDTH;
	put_image(&game->win, game->assets.letters[5], draw_x, draw_y);
	draw_y = draw_y + 128;
	draw_x = (game->map.columns - 1) / 2 * 64;
	put_image(&game->win, game->assets.skull, draw_x, draw_y);
}
