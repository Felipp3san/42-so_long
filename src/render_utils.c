/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:13:34 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 16:13:51 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_win *win, t_img *asset, int x, int y)
{
	t_xvar		*mlx;
	t_win_list	*win_lst;

	mlx = win->mlx;
	win_lst = win->win;
	mlx_put_image_to_window(mlx, win_lst, asset, x, y);
}
