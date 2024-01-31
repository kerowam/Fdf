/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:50:05 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/31 14:02:36 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_map(int key, t_map *map)
{
	if (key == 126)
		map->y_move -= 10;
	else if (key == 123)
		map->x_move -= 10;
	else if (key == 125)
		map->y_move += 10;
	else if (key == 124)
		map->x_move += 10;
}

void	zoom_map(int key, t_map *map)
{
	if (key == 30)
	{
		if (map->zoom < 11)
			map->zoom += 1;
		else if (map->zoom > 10 && map->zoom < 100)
			map->zoom += 5;
	}
	else if (key == 44)
	{
		if (map->zoom > 10)
			map->zoom -= 5;
		else if (map->zoom < 11 && map->zoom > 1)
			map->zoom -= 1;
	}
}

void	rotate_map(int key, t_map *map)
{
	if (key == 13)
		map->angle_y -= 0.2;
	else if (key == 1)
		map->angle_y += 0.2;
	else if (key == 0)
		map->angle_x += 0.2;
	else if (key == 2)
		map->angle_x -= 0.2;
}

void	change_deep(int key, t_map *map)
{
	if (key == 6)
		map->z_mod -= 1;
	else if (key == 7)
		map->z_mod += 1;
}

void	change_projection(t_map *map)
{
	if (map->projection == 0)
		map->projection = 1;
	else
		map->projection = 0;
}
