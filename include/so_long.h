/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:27:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/19 15:49:37 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx_int.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

#define MALLOC_ERROR -1
#define SUCCESS 0 

// Window 
#define NAME "So_long"
#define TILE_WIDTH 64 
#define TILE_HEIGHT 64 
#define MENU_HEIGHT 64

// Lives
#define MAX_LIVES 3 
#define EMPTY 0
#define FILLED 1

// Objects
#define OPEN 0
#define CLOSED 1

// Frames 
#define FRAMES 5

// Assets
#define FLOORS 3
#define NUMBERS 10
#define COLLECTABLES 3
#define HEARTS 2
#define DOORS 2

typedef struct s_point
{
	int	column;
	int	row;
}	t_point;

typedef struct s_win
{
	t_xvar		*mlx;
	t_win_list	*win;
	int			width;
	int			height;
}	t_win;

typedef struct s_map
{
	char	**map;
	char	*name;
	int		columns;
	int		rows;
	int		redraw;
	int		collectables;
	int		enemies;
	int		door_state;
	int		fd;
}	t_map;

typedef struct s_player
{
	t_point	location;
	int		lives;
	int		collectables;
	int		move_count;
}	t_player;

typedef struct s_enemy
{
	t_point	location;
	int		alive;
}	t_enemy;

typedef	struct s_assets
{
	t_img	*player;
	t_img	*wall;
	t_img	*floors[FLOORS];
	t_img	*hearts[HEARTS];
	t_img	*numbers[NUMBERS];
	t_img	*collectables[COLLECTABLES];
	t_img	*enemy[FRAMES];
	t_img	*torch[FRAMES];
	t_img	*doors[DOORS];
}	t_assets;

typedef struct s_frames
{
	int			frame_count;
	int			real_frame;
	int			last_frame;
}	t_frames;

typedef struct s_game
{
	t_win		win;
	t_map		map;
	t_enemy		*enemies;
	t_player	player;
	t_assets	assets;
	t_frames	frames;
}	t_game;

// Main 
void	clear_program(t_game *game);

// Map
void	free_map(t_map *map);
int		parse_map(t_map *map);
void	get_map_info(t_map *map, char *map_name);

// Player 
void	init_player(t_game *game);

// Enemies
void	init_enemies(t_game *game);

// Assets
void	free_assets(t_game *game);
void	load_assets(t_game *game);

// Render Utilse_hook.o obj/mlx_key_hook.o obj/mlx_expose_hook.o obj/mlx_loop_hook
void	put_image(t_win *win, t_img *asset, int x, int y);

// Render Map 
void	draw_background(t_game *game);
void	draw_walls(t_game *game);
void	draw_objects(t_game *game);
void	draw_torches(t_game *game);

// Render Entities
void	draw_player(t_game *game);
void	draw_enemies(t_game *game);

// Render UI
void	draw_hearts(t_game *game);
void	draw_movements(t_game *game);

// Events
int		close_window(void *param);
int		on_key_press(int key_code, void *param);

// Movement
void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);

#endif
