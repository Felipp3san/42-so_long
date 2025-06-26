/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:26:11 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 12:26:16 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx_int.h"
# include "libft.h"
# include "mlx.h"

# define MALLOC_ERROR -1

// Window 
# define NAME "So_long Bonus"
# define TILE_WIDTH 64 
# define TILE_HEIGHT 64 
# define MENU_HEIGHT 64

// Lives
# define MAX_LIVES 3

// Frames 
# define MAX_FRAME 4294967290
# define FRAMES 5
# define ANIMATION_SPEED 1000
# define MOVEMENT_SPEED 100000

// Assets
# define FLOORS 3
# define NUMBERS 10
# define LETTERS 9
# define HEARTS 2
# define DOORS 2
# define WALLS 2

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_game_state
{
	RUNNING,
	WIN,
	LOSE
}	t_game_state;

typedef enum e_letters
{
	E,
	I,
	L,
	N,
	O,
	S,
	U,
	W,
	Y
}	e_letters;

typedef enum e_direction
{
	UP,
	LEFT,
	DOWN,
	RIGHT
}	t_direction;

typedef enum e_door_state
{
	OPEN,
	CLOSED
}	t_door_state;

typedef enum e_heart_state
{
	EMPTY,
	FILLED
}	t_heart_state;

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
	int		collectable_count;
	int		player_count;
	int		enemy_count;
	int		exit_count;
	int		door_state;
}	t_map;

typedef struct s_player
{
	t_point	location;
	int		lives;
	int		collectables;
	int		move_count;
	int		hit;
}	t_player;

typedef struct s_enemy
{
	t_point	location;
	int		alive;
	int		next_direction;
}	t_enemy;

typedef struct s_assets
{
	t_img	*player;
	t_img	*skull;
	t_img	*crown;
	t_img	*hit;
	t_img	*walls[WALLS];
	t_img	*floors[FLOORS];
	t_img	*hearts[HEARTS];
	t_img	*numbers[NUMBERS];
	t_img	*letters[LETTERS];
	t_img	*collectables[FRAMES];
	t_img	*enemy[FRAMES];
	t_img	*torch[FRAMES];
	t_img	*doors[DOORS];
}	t_assets;

typedef struct s_frames
{
	unsigned int	frame_count;
	unsigned int	real_frame;
	unsigned int	last_frame;
}	t_frames;

typedef struct s_game
{
	t_frames	frames;
	t_win		win;
	t_map		map;
	t_player	player;
	t_enemy		*enemies;
	t_assets	assets;
	int			game_state;
}	t_game;

// main_bonus.c 
void	clear_program(t_game *game);

// game_loop_bonus.c
int		game_loop(void *param);

// map_bonus.c 
void	init_map(t_map *map, char *map_name);
int		parse_map(t_map *map);
void	extract_map_info(t_map *map);
void	validate_map(t_map *map);

// map_utils_bonus.c
int		open_map(char *map_name);
void	free_map(t_map *map);
void	free_map_exit(t_map *map, char *error);
char	**ft_clone_map(t_map *map);
void	set_tile(t_map *map, t_point *location, char value);

// map_validation_bonus.c
t_bool	has_invalid_tiles(t_map *map);
t_bool	has_equal_rows(t_map *map);
t_bool	has_valid_path(t_map *map);
t_bool	is_enclosed_by_walls(t_map *map);

// flood_fill_bonus.c
void	flood_fill(t_map *map, char **clone_map, t_point start);

// movements_bonus.c
void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);

// player_bonus.c 
t_point	get_player_location(t_map *map);
void	update_player_location(t_game *game, t_point *next, t_point *previous);
void	init_player(t_game *game);

// player_movements_bonus.c
void	handle_player_movement(t_game *game, t_point *next, t_point *previous);

// enemy_bonus.c
void	init_enemies(t_game *game);
void	move_enemies(t_game *game);
void	update_enemy_direction(t_enemy *enemy);
void	update_enemy_location(t_map *map, t_enemy *enemy, t_point *next);
t_enemy	*find_enemy(t_game *game, t_point *location);

// assets_bonus.c 
void	free_assets(t_game *game);
void	load_assets(t_game *game);

// asset_groups_bonus.c
void	load_numbers(t_game *game);
void	load_letters(t_game *game);
void	load_collectable_frames(t_game *game);
void	load_enemy_frames(t_game *game);
void	load_torch_frames(t_game *game);

// asset_utils_bonus.c
t_img	*open_img(t_game *game, char *path);

// render_utils_bonus.c
void	put_image(t_win *win, t_img *asset, int x, int y);
int		get_random_idx(int column, int row);

// render_map_bonus.c
void	draw_background(t_game *game);
void	draw_walls(t_game *game);
void	draw_collectables(t_game *game);
void	draw_torches(t_game *game);

// render_entities_bonus.c
void	draw_player(t_game *game);
void	draw_enemies(t_game *game);

// render_ui_bonus.c
void	draw_hearts_ui(t_game *game);
void	draw_movements_ui(t_game *game);
void	draw_lose(t_game *game);
void	draw_win(t_game *game);

// events_bonus.c
int		close_window(void *param);
int		on_key_press(int key_code, void *param);

#endif
