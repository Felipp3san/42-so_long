/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:27:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 04:14:15 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"
#include <math.h>

#define TILE_WIDTH 16
#define TILE_HEIGHT 16

typedef struct s_point
{
	int	column;
	int	row;
}	t_point;

typedef struct s_win
{
	t_xvar		*mlx;
	t_win_list	*win;
	char		*name;
	int			width;
	int			height;
}	t_win;

typedef struct s_map
{
	char	**map;
	char	*name;
	int		rows;
	int		columns;
	int		fd;
	t_point	player_location;
}	t_map;

typedef	struct s_assets
{
	t_img	*wall;
	t_img	*floor;
	t_img	*player;
	t_img	*collectable;
}	t_assets;

typedef struct s_game
{
	t_win		*win;
	t_map		*map;
	t_assets	*assets;
}	t_game;

// Main 
void	clear_program(t_win *win, t_map *map, t_assets *assets);

// Map
void	free_map(char **map);
void	parse_map(t_map *map);
void	get_map_info(t_map *map, char *map_name);
void	get_player_location(t_map *map);

// Assets
void	free_assets(t_assets *assets);
void	init_assets(t_win *win, t_map *map, t_assets *assets);

// Render
void	draw_map(t_win *win, t_map *map, t_assets *assets);
void	draw_player(t_win *win, t_map *map, t_assets *assets);
void	draw_objects(t_win *win, t_map *map, t_assets *assets);

// Events
int		on_key_press(int key_code, void *param);

// Movement
void	move_up(t_map *map);
void	move_right(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);

#endif
