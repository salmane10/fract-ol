/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:44:18 by slouham           #+#    #+#             */
/*   Updated: 2024/07/17 20:18:16 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

#include "fractol.h"

double	atodbl(char *s)
{
	int		i;
	double	pow;
	int		sign;
	long	intpart;
	double	fractional;

	i 			= 0;
	pow 		= 1;
	sign		= 1;
	intpart		= 0;
	fractional 	= 0;
	
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign *= -1;
	while (s[i] && s[i] != '.')
		intpart = (intpart * 10) + (s[i++] - '0');
	if ('.' == s[i])
		i++;
	while (s[i])
	{
		pow /= 10;
		fractional = fractional + (s[i++] - '0') * pow;
	}
	return ((intpart + fractional) * sign);
}
