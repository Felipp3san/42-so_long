/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_groups_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:24:21 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 12:24:24 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_numbers(t_game *game)
{
	t_assets	*assets;

	assets = &game->assets;
	assets->numbers[0] = open_img(game, "./textures/numbers/0.xpm");
	assets->numbers[1] = open_img(game, "./textures/numbers/1.xpm");
	assets->numbers[2] = open_img(game, "./textures/numbers/2.xpm");
	assets->numbers[3] = open_img(game, "./textures/numbers/3.xpm");
	assets->numbers[4] = open_img(game, "./textures/numbers/4.xpm");
	assets->numbers[5] = open_img(game, "./textures/numbers/5.xpm");
	assets->numbers[6] = open_img(game, "./textures/numbers/6.xpm");
	assets->numbers[7] = open_img(game, "./textures/numbers/7.xpm");
	assets->numbers[8] = open_img(game, "./textures/numbers/8.xpm");
	assets->numbers[9] = open_img(game, "./textures/numbers/9.xpm");
}

void	load_letters(t_game *game)
{
	t_assets	*assets;

	assets = &game->assets;
	assets->letters[0] = open_img(game, "./textures/letters/e.xpm");
	assets->letters[1] = open_img(game, "./textures/letters/i.xpm");
	assets->letters[2] = open_img(game, "./textures/letters/l.xpm");
	assets->letters[3] = open_img(game, "./textures/letters/n.xpm");
	assets->letters[4] = open_img(game, "./textures/letters/o.xpm");
	assets->letters[5] = open_img(game, "./textures/letters/s.xpm");
	assets->letters[6] = open_img(game, "./textures/letters/u.xpm");
	assets->letters[7] = open_img(game, "./textures/letters/w.xpm");
	assets->letters[8] = open_img(game, "./textures/letters/y.xpm");
}

void	load_collectable_frames(t_game *game)
{
	t_assets	*assets;

	assets = &game->assets;
	assets->collectables[0] = open_img(game, "./textures/collect_frame_1.xpm");
	assets->collectables[1] = open_img(game, "./textures/collect_frame_2.xpm");
	assets->collectables[2] = open_img(game, "./textures/collect_frame_3.xpm");
	assets->collectables[3] = open_img(game, "./textures/collect_frame_4.xpm");
	assets->collectables[4] = open_img(game, "./textures/collect_frame_5.xpm");
}

void	load_enemy_frames(t_game *game)
{
	t_assets	*assets;

	assets = &game->assets;
	assets->enemy[0] = open_img(game, "./textures/enemies/enemy_frame_1.xpm");
	assets->enemy[1] = open_img(game, "./textures/enemies/enemy_frame_2.xpm");
	assets->enemy[2] = open_img(game, "./textures/enemies/enemy_frame_3.xpm");
	assets->enemy[3] = open_img(game, "./textures/enemies/enemy_frame_4.xpm");
	assets->enemy[4] = open_img(game, "./textures/enemies/enemy_frame_5.xpm");
}

void	load_torch_frames(t_game *game)
{
	t_assets	*assets;

	assets = &game->assets;
	assets->torch[0] = open_img(game, "./textures/torch/torch_frame_1.xpm");
	assets->torch[1] = open_img(game, "./textures/torch/torch_frame_2.xpm");
	assets->torch[2] = open_img(game, "./textures/torch/torch_frame_3.xpm");
	assets->torch[3] = open_img(game, "./textures/torch/torch_frame_4.xpm");
	assets->torch[4] = open_img(game, "./textures/torch/torch_frame_5.xpm");
}
