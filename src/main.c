/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:28:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 17:18:17 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_win(t_win *win, t_map *map)
{
	win->width = map->columns * TILE_WIDTH;
	win->height = map->rows * TILE_HEIGHT + MENU_HEIGHT;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (MALLOC_ERROR);
	win->win = mlx_new_window(win->mlx, win->width, win->height, NAME);
	if (!win->win)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		return (MALLOC_ERROR);
	}
	return (SUCCESS);
}

void	clear_program(t_game *game)
{
	free_assets(game->win, game->assets);
	free_map(game->map);
	mlx_destroy_window(game->win->mlx, game->win->win);
	mlx_destroy_display(game->win->mlx);
	free(game->win->mlx);
}

int	game_loop(void *param)
{
	t_game	*game = (t_game *) param;

	if (game->map->redraw == 1)
	{
		draw_map(game);
		draw_objects(game);
		draw_player(game);
		draw_hearts(game);
		draw_movements(game);
		game->map->redraw = 0;
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_game		game;
	t_win		win;
	t_map		map;
	t_player	player;
	t_assets	assets;

	if (argc == 2)
	{
		get_map_info(&map, argv[1]);
		if (map.rows == 0)
			return (EXIT_FAILURE); 
		if(parse_map(&map) == MALLOC_ERROR)
			return (EXIT_FAILURE);
		if (initialize_win(&win, &map) == MALLOC_ERROR)
			return (free_map(&map), EXIT_FAILURE);
		game.map = &map;
		game.win = &win;
		game.player = &player;
		game.assets = &assets;
		init_player(&player, &map);
		init_assets(&game);
		mlx_loop_hook(win.mlx, game_loop, &game);
		mlx_key_hook(win.win, on_key_press, &game);
		mlx_loop(win.mlx);
		clear_program(&game);
	}
	return (EXIT_SUCCESS);
}
