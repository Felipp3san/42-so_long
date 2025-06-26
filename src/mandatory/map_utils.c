/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:59:19 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/19 21:25:07 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("Failed to open map file\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	free_map(t_map *map)
{
	int	row;

	row = 0;
	if (!map->map)
		return ;
	while (row < map->rows)
	{
		free(map->map[row]);
		row++;
	}
	free(map->map);
}

void	free_map_exit(t_map *map, char *error)
{
	free_map(map);
	ft_printf("Error\n");
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}

char	**ft_clone_map(t_map *map)
{
	char	**clone_map;
	int		i;

	clone_map = (char **) malloc(sizeof(char *) * map->rows);
	if (!clone_map)
		free_map_exit(map, "Failed to clone map.");
	i = 0;
	while (i < map->rows)
	{
		clone_map[i] = ft_strdup(map->map[i]);
		if (!clone_map[i])
		{
			while (i >= 0)
				free(clone_map[i--]);
			free(clone_map);
			return (NULL);
		}
		i++;
	}
	return (clone_map);
}

void	set_tile(t_map *map, t_point *location, char value)
{
	map->map[location->row][location->column] = value;
}
