/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:56:13 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 22:55:04 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_assets(t_game *game)
{
	t_assets	*assets;
	t_win		*win;
	int			i;

	win = &game->win;
	assets = &game->assets;
	mlx_destroy_image(win->mlx, assets->wall);
	mlx_destroy_image(win->mlx, assets->player);
	i = 0;
	while (i < FLOORS)
		mlx_destroy_image(win->mlx, assets->floors[i++]);
	i = 0;
	while (i < DOORS)
		mlx_destroy_image(win->mlx, assets->doors[i++]);
	i = 0;
	while (i < NUMBERS)
		mlx_destroy_image(win->mlx, assets->numbers[i++]);
	i = 0;
	while (i < COLLECTABLES)
		mlx_destroy_image(win->mlx, assets->collectables[i++]);
	i = 0;
	while (i < HEARTS)
		mlx_destroy_image(win->mlx, assets->hearts[i++]);
	i = 0;
	while (i < FRAMES)
	{
		mlx_destroy_image(win->mlx, assets->enemy[i]);
		mlx_destroy_image(win->mlx, assets->torch[i]);
		i++;
	}
}

t_img	*open_img(t_game *game, char *path)
{
	t_img	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->win.mlx, path, &img_width, &img_height);
	if (!img)
	{
		perror("mlx_xpm_file_to_image failed");
		clear_program(game);
		exit(EXIT_FAILURE);
	}
	return (img);
}

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

void	load_collectables(t_game *game)
{
	t_assets	*assets;
	
	assets = &game->assets;
	assets->collectables[0] = open_img(game, "./textures/collectable_1.xpm");
	assets->collectables[1] = open_img(game, "./textures/collectable_2.xpm");
	assets->collectables[2] = open_img(game, "./textures/collectable_3.xpm");
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
	load_collectables(game);
	load_enemy_frames(game);
	load_torch_frames(game);
}
