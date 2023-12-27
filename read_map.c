/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:18:10 by gfredes-          #+#    #+#             */
/*   Updated: 2023/12/27 03:16:07 by gfredes-         ###   ########.fr       */
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

void	make_map_line(int *z_y, char *line, t_map *map, int x)
{
	char	**z;
	int		i;

	z = ft_split(line, ' ');
	i = 0;
	/*if (!z_y)
	{
		z_y = (int *)malloc(sizeof(int) * (map->width + 1));
		if (!z_y)
			return ;
		map->z_values[x] = z_y;
	}*/
	while (z[i])
	{
		z_y[i] = ft_atoi(z[i]);
		free (z[i]);
		i++;
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
	map->z_values = (int **)malloc(sizeof(int) * (map->height));
	if (!(map->z_values))
		return ;
	i = 0;
	while (i < map->height)
	{
		map->z_values[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		if (!(map->z_values[i]))
			return ;
		i++;
	}
	i = 0;
	fd = open(map_file, O_RDONLY, 0);
	while (i <= map->height)
	{
		line = get_next_line(fd);
		if (line)
			make_map_line(map->z_values[i], line, map, i);
		free (line);
		i++;
	}
	close(fd);
	map->z_values[i] = NULL;
}
