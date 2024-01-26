/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:48:34 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/20 23:00:40 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->window_ptr);
	exit (0);
}

int	key_hook(int key, t_map *map)
{
	printf("%d\n", key);
	if (key == 53)
		close_window(map);
	else
	{
		if (key >= 65361 && key <= 65364)
			move_map(key, map);
		else if (key == 43 || key == 45)
			zoom_map (key, map);
		else if (key == 119 || key == 115 || key == 97 || key == 100)
			rotate_map(key, map);
		else if (key == 122 || key == 120)
			change_deep(key, map);
		else if (key == 112)
			change_projection(map);
		mlx_clear_window(map->mlx_ptr, map->window_ptr);
		draw_sequence(map);
	}
	return (0);
}

