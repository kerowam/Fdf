/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:12:38 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 17:47:49 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	isometric_projection(float *x, float *y, int z, t_map *map)
{
	*x = (*x - *y) * cos(map->angle_x);
	*y = (*x + *y) * sin(map->angle_y) - z;
}

void	cavalier_projection(float *x, float *y, int z, t_map *map)
{
	*x = *x + (z * cos(map->angle_x));
	*y = *y + (z * sin (map->angle_y));
}

void	select_projection(t_map	*map)
{
	if (map->projection == 0)
	{
		isometric_projection(&map->x, &map->y, map->z, map);
		isometric_projection(&map->x1, &map->y1, map->z1, map);
	}
	else if (map->projection == 1)
	{
		cavalier_projection(&map->x, &map->y, map->z, map);
		cavalier_projection(&map->x1, &map->y1, map->z1, map);
	}
}
