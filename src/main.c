/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:28:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 04:14:17 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_win(t_win *win, t_map *map)
{
	win->name = "So_long";
	win->width = map->columns * 64;
	win->height = map->rows * 64 + 64;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (-1);
	win->win = mlx_new_window(win->mlx, win->width, win->height, win->name);
	if (!win->win)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		return (-1);
	}
	return (1);
}

void	clear_program(t_win *win, t_map *map, t_assets *assets)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	free_map(map->map);
	free_assets(assets);
}

int	game_loop(void *param)
{
	t_game	*game = (t_game *) param;

	draw_map(game->win, game->map, game->assets);
	draw_objects(game->win, game->map, game->assets);
	draw_player(game->win, game->map, game->assets);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game		game;
	t_map		map;
	t_win		win;
	t_assets	assets;

	if (argc == 2)
	{
		get_map_info(&map, argv[1]);
		if (map.rows == 0)
			return (1); 
		parse_map(&map);
		get_player_location(&map);
		if (!initialize_win(&win, &map))
			return (1);
		init_assets(&win, &map, &assets);
		game.map = &map;
		game.win = &win;
		game.assets = &assets;
		mlx_loop_hook(win.mlx, game_loop, &game);
		mlx_key_hook(win.win, on_key_press, &game);
		mlx_loop(win.mlx);
		clear_program(&win, &map, &assets);
	}
	return (0);
}
