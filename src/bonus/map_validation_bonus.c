/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:29:38 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 12:29:41 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_enclosed_by_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->columns)
	{
		if (map->map[0][i] != '1' || map->map[map->rows - 1][i] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1' || map->map[i][map->columns - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	has_unreacheable_tiles(t_map *map, char **clone_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (clone_map[i][j] == 'E' || clone_map[i][j] == 'C')
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

static int	has_valid_path(t_map *map)
{
	int		i;
	int		unreachable_exist;
	char	**clone_map;
	t_point	start;

	start = get_player_location(map);
	clone_map = ft_clone_map(map);
	if (!clone_map)
		free_map_exit(map, "Failed to clone map.");
	flood_fill(map, clone_map, start);
	unreachable_exist = has_unreacheable_tiles(map, clone_map);
	i = 0;
	while (i < map->rows)
		free(clone_map[i++]);
	free(clone_map);
	return (!unreachable_exist);
}

static int	has_equal_rows(t_map *map)
{
	int		i;
	size_t	row_size;

	row_size = 0;
	i = 0;
	while (i < map->rows)
	{
		if (row_size == 0)
			row_size = ft_strlen(map->map[i]);
		else
		{
			if (row_size != ft_strlen(map->map[i]))
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	validate_map(t_map *map)
{
	if (map->rows == 0)
		free_map_exit(map, "Map is empty.");
	if (!has_equal_rows(map))
		free_map_exit(map, "Map is not rectangular.");
	if (map->exit_count > 1)
		free_map_exit(map, "Map has more than 1 exit.");
	if (map->exit_count == 0)
		free_map_exit(map, "Map has no exit.");
	if (map->player_count > 1)
		free_map_exit(map, "Map has more than 1 player.");
	if (map->player_count == 0)
		free_map_exit(map, "Map has no player.");
	if (map->collectable_count < 1)
		free_map_exit(map, "Map has no collectables.");
	if (!is_enclosed_by_walls(map))
		free_map_exit(map, "Map is not enclosed by walls.");
	if (!has_valid_path(map))
		free_map_exit(map, "Map has no valid path.");
}
