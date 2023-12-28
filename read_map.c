/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:18:10 by gfredes-          #+#    #+#             */
/*   Updated: 2023/12/28 22:07:46 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *map_file)
{
	int	height;
	int	fd;

	fd = open(map_file, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close (fd);
	return (height);
}

int	word_counter(char *line, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (line[0] != c)
		counter++;
	i++;
	while (line[i])
	{
		if (line[i] == c && line[i + 1] != c && line[i + 1] != '\n'
				&& line[i + 1] != '\0')
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

int	get_width(char *map_file)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY, 0);
	line = get_next_line(fd);
	width = word_counter(line, ' ');
	free(line);
	while (get_next_line(fd))
		get_next_line(fd);
	close(fd);
	return (width);
}

void	set_color(t_map *map, char **z, int x, int y)
{
	if (ft_strchr(*z, ','))
		map->z_color[y][x] = ft_atoi_base(ft_strchr(*z, ','), 16);
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
	/*if (!z_y)
	{
		z_y = (int *)malloc(sizeof(int) * (map->width + 1));
		if (!z_y)
			return ;
		map->z_values[x] = z_y;
	}*/
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

void	read_map(char *map_file, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	line = NULL;
	map->height = get_height(map_file);
	map->width = get_width(map_file);
	map->z_values = (int **)malloc(sizeof(int *) * (map->height + 1));
	map->z_color = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (!(map->z_values) || !(map->z_color))
		return ;
	i = 0;
	while (i <= map->height)
	{
		map->z_values[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		map->z_color[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		if (!(map->z_values[i]) || !(map->z_color[i]))
			return ;
		i++;
	}
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
	map->z_values[i] = NULL;
	map->z_color[i] = NULL;
}
