/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:13:47 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 17:48:12 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	get_height(char *map_file, t_map *map)
{
	int	height;
	int	fd;

	fd = open(map_file, O_RDONLY, 0);
	height = 0;
	while (1)
	{
		map->line = get_next_line(fd);
		if (height == 0 && map->line == NULL)
		{
			ft_putstr_fd("Can't open file. Something is wrong!\n", 1);
			exit(EXIT_FAILURE);
		}
		if (map->line == NULL)
			break ;
		height++;
		free(map->line);
	}
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
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free (line);
	}
	close(fd);
	return (width);
}
