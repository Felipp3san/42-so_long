/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:12:28 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/21 01:23:17 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_to_letter_idx(char ch)
{
	if (ch == 'Y')
		return (Y);
	else if (ch == 'O')
		return (O);
	else if (ch == 'U')
		return (U);
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
	draw_y = draw_y + TILE_HEIGHT;
	draw_x = ((game->win.width / 2) - ((TILE_WIDTH * 2) / 2));
	put_image(&game->win, game->assets.crown, draw_x, draw_y);
}
