/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:11:41 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 03:30:40 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_z_z1(t_map *map, float x, float y)
{
	float	x1;
	float	y1;

	map->z = map->z_values[(int)y][(int)x] * map->z_mod;
	x = map->x;
	y = map->y;
	x1 = map->x1;
	y1 = map->y1;
	map->z1 = map->z_values[(int)y1][(int)x1] * map->z_mod;
}

void	set_x1_y1(int x1, int y1, t_map *map)
{
	map->x1 = (float)x1;
	map->y1 = (float)y1;
}

void	set_x_y(int x, int y, t_map *map)
{
	map->x = (float)x;
	map->y = (float)y;
}
