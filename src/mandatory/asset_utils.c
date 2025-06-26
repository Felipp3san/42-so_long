/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:33:42 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/19 18:33:56 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*open_img(t_game *game, char *path)
{
	t_img	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->win.mlx, path, &img_width, &img_height);
	if (!img)
	{
		ft_printf("Error\n");
		ft_printf("mlx_xpm_file_to_image failed\n");
		clear_program(game);
		exit(EXIT_FAILURE);
	}
	return (img);
}
