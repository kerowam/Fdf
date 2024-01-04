/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:14:15 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 02:14:42 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_map *map, char **z, int x, int y)
{
	char	*z_pnt;

	z_pnt = *z;
	if (ft_strchr(z_pnt, ','))
		map->z_color[y][x] = ft_atoi_base(ft_strchr(z_pnt, ','), 16);
	else
	{
		if (ft_atoi(*z) > 0)
			map->z_color[y][x] = 0x56ca1f;
		else if (ft_atoi(*z) == 0)
			map->z_color[y][x] = 0xffffff;
		else if (ft_atoi(*z) < 0)
			map->z_color[y][x] = 0x2424e7;
	}
}

void	make_map_line(int *z_y, char *line, t_map *map, int y)
{
	char	**z;
	int		x;

	z = ft_split(line, ' ');
	x = 0;

	while (z[x])
	{
		if (x < map->width)
		{
			z_y[x] = ft_atoi(z[x]);
			set_color(map, &z[x], x, y);
		}
		free (z[x]);
		x++;
	}
	free (z);
}

void	init_z(t_map *map)
{
	int	i;

	i = 0;

	map->z_values = (int **)malloc(sizeof(int *) * (map->height));
	map->z_color = (int **)malloc(sizeof(int *) * (map->height));
	if (!(map->z_values) || !(map->z_color))
		return ;
	while (i < map->height)
	{
		map->z_values[i] = (int *)malloc(sizeof(int) * (map->width));
		map->z_color[i] = (int *)malloc(sizeof(int) * (map->width));
		if (!(map->z_values[i]) || !(map->z_color[i]))
			return ;
		i++;
	}
}

void	read_map(char *map_file, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	line = NULL;
	map->height = get_height(map_file, map);
	map->width = get_width(map_file);
	init_z(map);
	i = 0;
	fd = open(map_file, O_RDONLY, 0);
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (line)
			make_map_line(map->z_values[i], line, map, i);
		free (line);
		i++;
	}
	close(fd);
}
