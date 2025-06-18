/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:28:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 13:38:29 by fde-alme         ###   ########.fr       */
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

void	clear_program(t_win *win, t_map *map, t_assets *assets)
{
	free_assets(win, assets);
	free_map(map);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
}

int	game_loop(void *param)
{
	t_game	*game = (t_game *) param;

	if (game->map->redraw == 1)
	{
		draw_map(game->win, game->map, game->assets);
		draw_objects(game->win, game->map, game->assets);
		draw_player(game->win, game->assets, game->player);
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
		init_player(&player, &map);
		init_assets(&win, &map, &assets);
		game.map = &map;
		game.win = &win;
		game.player = &player;
		game.assets = &assets;
		mlx_loop_hook(win.mlx, game_loop, &game);
		mlx_key_hook(win.win, on_key_press, &game);
		mlx_loop(win.mlx);
		clear_program(&win, &map, &assets);
	}
	return (EXIT_SUCCESS);
}
