/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:34:22 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/20 22:49:09 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->window_ptr);
	exit (0);
}

int	key_hook(int key, t_map *map)
{
	(void)map;
	if (key == 53)
		close_window(map);
	else
	{
		if (key == 126)
			map->y_move -= 10;
		else if (key == 123)
			map->x_move -= 10;
		else if (key == 125)
			map->y_move += 10;
		else if (key == 124)
			map->x_move += 10;
		mlx_clear_window(map->mlx_ptr, map->window_ptr);
		draw_sequence(map);
	}
	return (0);
}
