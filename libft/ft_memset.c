/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:49:37 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/29 18:22:44 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			count;
	unsigned char	*dst;

	count = 0;
	dst = (unsigned char *) dest;
	while (count < len)
	{
		dst[count] = (unsigned char) c;
		count++;
	}
	return (dest);
}
