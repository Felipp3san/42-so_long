/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:56:13 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 17:49:23 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_assets(t_win *win, t_assets *assets)
{
	int	i;

	if (assets->wall)
		mlx_destroy_image(win->mlx, assets->wall);
	if (assets->player)
		mlx_destroy_image(win->mlx, assets->player);
	if (assets->floor)
		mlx_destroy_image(win->mlx, assets->floor);
	if (assets->door_opened)
		mlx_destroy_image(win->mlx, assets->door_opened);
	if (assets->door_closed)
		mlx_destroy_image(win->mlx, assets->door_closed);
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
	while (i < ENEMIES)
		mlx_destroy_image(win->mlx, assets->enemies[i++]);
	
}

t_img	*open_map_tile(t_game *game, char *path)
{
	t_img	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->win->mlx, path, &img_width, &img_height);
	if (!img)
	{
		perror("mlx_xpm_file_to_image failed");
		clear_program(game);
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	init_numbers(t_game *game)
{
	game->assets->numbers[0] =
		open_map_tile(game, "./textures/numbers/0.xpm");
	game->assets->numbers[1] =
		open_map_tile(game, "./textures/numbers/1.xpm");
	game->assets->numbers[2] =
		open_map_tile(game, "./textures/numbers/2.xpm");
	game->assets->numbers[3] =
		open_map_tile(game, "./textures/numbers/3.xpm");
	game->assets->numbers[4] =
		open_map_tile(game, "./textures/numbers/4.xpm");
	game->assets->numbers[5] =
		open_map_tile(game, "./textures/numbers/5.xpm");
	game->assets->numbers[6] =
		open_map_tile(game, "./textures/numbers/6.xpm");
	game->assets->numbers[7] =
		open_map_tile(game, "./textures/numbers/7.xpm");
	game->assets->numbers[8] =
		open_map_tile(game, "./textures/numbers/8.xpm");
	game->assets->numbers[9] =
		open_map_tile(game, "./textures/numbers/9.xpm");
}

void	init_collectables(t_game *game)
{
	game->assets->collectables[0] = 
		open_map_tile(game, "./textures/collectable_1.xpm");
	game->assets->collectables[1] = 
		open_map_tile(game, "./textures/collectable_2.xpm");
	game->assets->collectables[2] = 
		open_map_tile(game, "./textures/collectable_3.xpm");
}

void	init_enemies(t_game *game)
{
	game->assets->enemies[0] = 
		open_map_tile(game, "./textures/enemies/enemy_1.xpm");
	game->assets->enemies[1] = 
		open_map_tile(game, "./textures/enemies/enemy_2.xpm");
}

void	init_assets(t_game *game)
{
	game->assets->wall = 
		open_map_tile(game, "./textures/wall.xpm");
	game->assets->player = 
		open_map_tile(game, "./textures/player.xpm");
	game->assets->floor = 
		open_map_tile(game, "./textures/floor.xpm");
	game->assets->door_opened = 
		open_map_tile(game, "./textures/door_opened.xpm");
	game->assets->door_closed = 
		open_map_tile(game, "./textures/door_closed.xpm");
	game->assets->hearts[EMPTY_HEART] =
		open_map_tile(game, "./textures/empty_heart.xpm");
	game->assets->hearts[FILLED_HEART] =
		open_map_tile(game, "./textures/filled_heart.xpm");
	init_numbers(game);
	init_collectables(game);
	init_enemies(game);
}
