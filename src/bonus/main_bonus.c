/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:24:51 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 12:24:53 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clear_program(t_game *game)
{
	t_win	*win;
	t_map	*map;

	win = &game->win;
	map = &game->map;
	free(game->enemies);
	free_map(map);
	free_assets(game);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
}

static int	init_win(t_game *game)
{
	t_map	*map;
	t_win	*win;

	win = &game->win;
	map = &game->map;
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
	return (0);
}

static void	init_frames(t_frames *frames)
{
	frames->frame_count = 0;
	frames->real_frame = 0;
	frames->last_frame = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nUsage: ./so_long_bonus path/to/map\n"), 1);
	init_map(&game.map, argv[1]);
	extract_map_info(&game.map);
	if (parse_map(&game.map) == MALLOC_ERROR)
		return (EXIT_FAILURE);
	validate_map(&game.map);
	if (init_win(&game) == MALLOC_ERROR)
		return (free_map(&game.map), EXIT_FAILURE);
	init_frames(&game.frames);
	init_player(&game);
	init_enemies(&game);
	load_assets(&game);
	draw_walls(&game);
	game.game_state = RUNNING;
	mlx_loop_hook(game.win.mlx, game_loop, &game);
	mlx_hook(game.win.win, 17, StructureNotifyMask, close_window, &game);
	mlx_key_hook(game.win.win, on_key_press, &game);
	mlx_loop(game.win.mlx);
	clear_program(&game);
	return (EXIT_SUCCESS);
}
