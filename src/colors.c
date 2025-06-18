/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:28:30 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/17 21:28:34 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	put_gradient(t_data *img)
{
	int	x;
	int y;
	int	color;
	int	r;
	int	g;
	int	b;

	y = 0;
	while (y < HEIGHT)
	{
		r = 255;
		g = 0;
		b = 100;
		x = 0;
		while (x < WIDTH)
		{
			if (x % 4 == 0)
			{
				if (r > 0)
					r--;
				if (b < 255)
					b++;
			}
			color = create_rgb(r,g,b);
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}
