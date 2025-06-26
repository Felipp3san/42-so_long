/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:56:13 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/21 01:29:28 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_image_array(t_xvar *mlx, t_img **assets, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (assets[i])
		{
			mlx_destroy_image(mlx, assets[i]);
			assets[i] = NULL;
		}
		i++;
	}
}

void	free_assets(t_game *game)
{
	t_assets	*assets;
	t_win		*win;

	win = &game->win;
	assets = &game->assets;
	if (assets->crown)
		mlx_destroy_image(win->mlx, assets->crown);
	if (assets->player)
		mlx_destroy_image(win->mlx, assets->player);
	if (assets->torch)
		mlx_destroy_image(win->mlx, assets->torch);
	if (assets->collectable)
		mlx_destroy_image(win->mlx, assets->collectable);
	destroy_image_array(win->mlx, assets->walls, WALLS);
	destroy_image_array(win->mlx, assets->floors, FLOORS);
	destroy_image_array(win->mlx, assets->doors, DOORS);
	destroy_image_array(win->mlx, assets->numbers, NUMBERS);
	destroy_image_array(win->mlx, assets->letters, LETTERS);
}

static void	init_as_null(t_img **assets, int count)
{
	int	i;

	i = 0;
	while (i < count)
		assets[i++] = NULL;
}

static void	init_assets(t_game *game)
{
	t_assets	*assets;

	assets = &game->assets;
	assets->crown = NULL;
	assets->player = NULL;
	assets->collectable = NULL;
	assets->torch = NULL;
	init_as_null(assets->walls, WALLS);
	init_as_null(assets->floors, FLOORS);
	init_as_null(assets->doors, DOORS);
	init_as_null(assets->numbers, NUMBERS);
	init_as_null(assets->letters, LETTERS);
}

void	load_assets(t_game *game)
{
	t_assets	*assets;

	assets = &game->assets;
	init_assets(game);
	assets->crown = open_img(game, "./textures/crown.xpm");
	assets->player = open_img(game, "./textures/player.xpm");
	assets->walls[0] = open_img(game, "./textures/wall.xpm");
	assets->walls[1] = open_img(game, "./textures/wall_2.xpm");
	assets->floors[0] = open_img(game, "./textures/floor_1.xpm");
	assets->floors[1] = open_img(game, "./textures/floor_2.xpm");
	assets->floors[2] = open_img(game, "./textures/floor_3.xpm");
	assets->doors[OPEN] = open_img(game, "./textures/door_opened.xpm");
	assets->doors[CLOSED] = open_img(game, "./textures/door_closed.xpm");
	assets->collectable = open_img(game, "./textures/collect_frame_1.xpm");
	assets->torch = open_img(game, "./textures/torch/torch_frame_1.xpm");
	load_numbers(game);
	load_letters(game);
}
