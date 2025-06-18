/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:07:37 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/17 23:08:07 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_key_press(int key_code, t_win *win)
{
	(void) win;
	ft_printf("Hello from key_hook. KeyCode: %d\n", key_code);
	return (0);
}
