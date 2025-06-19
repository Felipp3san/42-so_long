/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:56:13 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/19 18:41:02 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_image_array(t_xvar *mlx, t_img **assets, int count)
{
	int	i;

	i = 0;
	while (i < count)
		mlx_destroy_image(mlx, assets[i++]);
}

void	free_assets(t_game *game)
{
	t_assets	*assets;
	t_win		*win;

	win = &game->win;
	assets = &game->assets;
	mlx_destroy_image(win->mlx, assets->wall);
	mlx_destroy_image(win->mlx, assets->player);
	destroy_image_array(win->mlx, assets->floors, FLOORS);
	destroy_image_array(win->mlx, assets->doors, DOORS);
	destroy_image_array(win->mlx, assets->numbers, NUMBERS);
	destroy_image_array(win->mlx, assets->collectables, FRAMES);
	destroy_image_array(win->mlx, assets->hearts, HEARTS);
	destroy_image_array(win->mlx, assets->enemy, FRAMES);
	destroy_image_array(win->mlx, assets->torch, FRAMES);
}

void	load_assets(t_game *game)
{
	t_assets	*assets;

	assets = &game->assets;
	assets->wall = open_img(game, "./textures/wall.xpm");
	assets->player = open_img(game, "./textures/player.xpm");
	assets->floors[0] = open_img(game, "./textures/floor_1.xpm");
	assets->floors[1] = open_img(game, "./textures/floor_2.xpm");
	assets->floors[2] = open_img(game, "./textures/floor_3.xpm");
	assets->doors[OPEN] = open_img(game, "./textures/door_opened.xpm");
	assets->doors[CLOSED] = open_img(game, "./textures/door_closed.xpm");
	assets->hearts[EMPTY] = open_img(game, "./textures/empty_heart.xpm");
	assets->hearts[FILLED] = open_img(game, "./textures/filled_heart.xpm");
	load_numbers(game);
	load_collectable_frames(game);
	load_enemy_frames(game);
	load_torch_frames(game);
}
