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

t_bool	is_enclosed_by_walls(t_map *map)
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

t_bool	has_unreacheable_tiles(t_map *map, char **clone_map)
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

t_bool	has_valid_path(t_map *map)
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

t_bool	has_equal_rows(t_map *map)
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

t_bool	has_invalid_tiles(t_map *map)
{
	int		row;
	int		column;
	char	tile;

	row = 0;
	while (row < map->rows)
	{
		column = 0;
		while (column < map->columns)
		{
			tile = map->map[row][column]; 
			if (tile != '0' && tile != '1' && tile != 'C' 
				&& tile != 'E' && tile != 'P')
					return (TRUE);
			column++;
		}
		row++;
	}
	return (FALSE);
}
