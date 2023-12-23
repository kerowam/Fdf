/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:00:19 by gfredes-          #+#    #+#             */
/*   Updated: 2023/12/23 22:06:30 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_values;
}			t_map;

void	read_map(char *map_file, t_map *map);
char	*get_next_line(int fd);
int		ft_atoi(const char *str);

#endif