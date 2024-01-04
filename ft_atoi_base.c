/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:07:40 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 19:36:00 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int	get_digit(char c, int digits_in_base)
{
	int	max_digit;

	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int	getting_digits(const char *str, int str_base, int sign)
{
	int	result;
	int	digit;

	result = 0;
	while (1)
	{
		digit = get_digit(to_lower(*str), str_base);
		if (digit >= 0)
		{
			result = result * str_base;
			result = result + (digit * sign);
			++str;
		}
		else
			return (result);
	}
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == ',')
		++str;
	if (*str == '0')
		++str;
	if (*str == 'x')
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	result = getting_digits(str, str_base, sign);
	return (result);
}
