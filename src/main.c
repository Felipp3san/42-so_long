/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:28:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 00:55:28 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_win(t_win *win, t_map_info *map_info)
{
	win->name = "So_long";
	win->width = map_info->columns * 64;
	win->height = map_info->rows * 64 + 64;
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

void	clear_program(t_win *win, char **map)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	free_map(map);
}

int	main(int argc, char *argv[])
{
	char			**map;
	t_win			win;
	t_map_info		map_info;
	t_game_assets	assets;

	if (argc == 2)
	{
		init_assets(&assets);
		get_map_info(&map_info, argv[1]);
		map = parse_map(&map_info, argv[1]);
		if (!initialize_win(&win, &map_info))
			return (1);
		//mlx_key_hook(vars.win, on_key_press, &vars);
		draw_map(&win, map, &map_info);
		draw_objects(&win, map, &map_info);
		mlx_loop(win.mlx);
		clear_program(&win, map);
	}
	return (0);
}
