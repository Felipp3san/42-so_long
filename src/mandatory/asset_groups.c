/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_groups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:33:23 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/20 23:30:44 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_letters(t_game *game)
{
	t_assets	*assets;

	assets = &game->assets;
	assets->letters[0] = open_img(game, "./textures/letters/y.xpm");
	assets->letters[1] = open_img(game, "./textures/letters/o.xpm");
	assets->letters[2] = open_img(game, "./textures/letters/u.xpm");
	assets->letters[3] = open_img(game, "./textures/letters/w.xpm");
	assets->letters[4] = open_img(game, "./textures/letters/i.xpm");
	assets->letters[5] = open_img(game, "./textures/letters/n.xpm");
}
