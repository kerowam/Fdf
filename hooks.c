/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:34:22 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 19:36:54 by gfredes-         ###   ########.fr       */
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
	if (key == 65307)
		close_window(map);
	else
	{
		if (key == 65362)
			map->y_move -= 10;
		else if (key == 65361)
			map->x_move -= 10;
		else if (key == 65364)
			map->y_move += 10;
		else if (key == 65363)
			map->x_move += 10;
		mlx_clear_window(map->mlx_ptr, map->window_ptr);
		draw_sequence(map);
	}
	return (0);
}

/*int	loop_hook(int key, void *param)
{
	//t_map	*map;

	(void)param;
	return (0);
}*/
