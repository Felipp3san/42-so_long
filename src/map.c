/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:33:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/17 23:09:23 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map_name)
{
	int	fd;
	
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	return (fd);
}

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

char	**parse_map(t_map_info *map_info, char *map_name)
{
	char	**map;
	char	*line;
	int		map_fd;
	int		i;
	int		j;

	map_fd = open_map(map_name);
	map = (char **) malloc(sizeof(char *) * map_info->rows + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (i < map_info->rows)
	{
		j = 0;
		map[i] = (char *) malloc(map_info->columns + 1);
		if (!map[i])
			return (free_map(map), NULL);
		line = get_next_line(map_fd);
		while (line[j] && line[j] != '\n')
		{
			map[i][j] = line[j];
			j++;
		}
		free(line);
		i++;
	}
	map[i] = NULL;
	close(map_fd);
	return (map);
}

void	get_map_info(t_map_info *map_info, char *map_name)
{
	char	*line;
	int		map_fd;

	map_info->rows = 0;
	map_info->columns = 0;
	map_fd = open_map(map_name);
	line = get_next_line(map_fd);
	while (line)
	{
		while (line[map_info->columns] && line[map_info->columns] != '\n')
			map_info->columns++;
		free(line);
		line = get_next_line(map_fd);
		map_info->rows++;
	}
	close(map_fd);
}
