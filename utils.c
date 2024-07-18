/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:44:18 by slouham           #+#    #+#             */
/*   Updated: 2024/07/18 17:55:15 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid(char *str)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (f)
				return (0);
			f = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

double	atodbl(char *s)
{
	double	pow;
	int		sign;
	long	intpart;
	double	fractional;

	pow = 1;
	sign = 1;
	intpart = 0;
	fractional = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign *= -1;
	while (*s && *s != '.')
		intpart = (intpart * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		fractional = fractional + (*s++ - '0') * pow;
	}
	return ((intpart + fractional) * sign);
}
