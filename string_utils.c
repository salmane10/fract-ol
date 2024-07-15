#include "fractol.h"

double	atodbl(char *s)
{
	long	intpart;
	double	fractional;
	double	pow;
	int	sign;
	int	i;

	integer_part	= 0;
	fractional_part = 0;
	sign		= 1;
	pow 		= 1;
	i 		= 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign *= -1;
	while (s[i] && s[i] != '.')
		intpart = (intpart * 10) + (s[i++] - '0');
	if ('.' == *s)
		s[i++];
	while (s[i])
	{
		pow /= 10;
		fractional = fractional + (s[i++] - '0') * pow;
	}
	return ((intpart + fractional) * sign);
}
