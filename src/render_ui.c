/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:12:28 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/21 00:06:00 by fde-alme         ###   ########.fr       */
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

int	char_to_letter_idx(char ch)
{
	if (ch == 'Y')
		return (Y);
	else if (ch == 'O')
		return (O);
	else if (ch == 'U')
		return (U);
	else if (ch == 'L')
		return (L);
	else if (ch == 'O')
		return (O);
	else if (ch == 'S')
		return (S);
	else if (ch == 'E')
		return (E);
	else if (ch == 'W')
		return (W);
	else if (ch == 'I')
		return (I);
	else if (ch == 'N')
		return (N);
	else
		return (-1);
}

void	draw_win(t_game *game)
{
	const char	message[] = "YOU WIN";
	int			draw_x;
	int			draw_y;
	int			idx;
	int			i;

	i = 0;
	draw_x = ((game->win.width / 2) - ((TILE_WIDTH * 7) / 2));
	draw_y = ((game->win.height / 2) - (TILE_HEIGHT / 2));
	mlx_clear_window(game->win.mlx, game->win.win);
	while (i < 7)
	{
		idx = char_to_letter_idx(message[i]);
		if (idx != -1)
			put_image(&game->win, game->assets.letters[idx], draw_x, draw_y);
		draw_x = draw_x + TILE_WIDTH;
		i++;
	}
	draw_y = draw_y + (TILE_HEIGHT * 2);
	draw_x = ((game->win.width / 2) - ((TILE_WIDTH * 2) / 2));
	put_image(&game->win, game->assets.crown, draw_x, draw_y);
}

void	draw_lose(t_game *game)
{
	const char	message[] = "YOU LOSE";
	int			draw_x;
	int			draw_y;
	int			idx;
	int			i;

	i = 0;
	draw_x = ((game->win.width / 2) - ((TILE_WIDTH * 8) / 2));
	draw_y = ((game->win.height / 2) - (TILE_HEIGHT / 2));
	mlx_clear_window(game->win.mlx, game->win.win);
	while (i < 8)
	{
		idx = char_to_letter_idx(message[i]);
		if (idx != -1)
			put_image(&game->win, game->assets.letters[idx], draw_x, draw_y);
		draw_x = draw_x + TILE_WIDTH;
		i++;
	}
	draw_y = draw_y + (TILE_HEIGHT * 2);
	draw_x = ((game->win.width / 2) - ((TILE_WIDTH * 2) / 2));
	put_image(&game->win, game->assets.skull, draw_x, draw_y);
}
