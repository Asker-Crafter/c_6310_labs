#include "../inc/libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		if (num * sign > INT_MAX)
			return (INT_MAX);
		if (num * sign < INT_MIN)
			return (INT_MIN);
		nptr++;
	}
	return ((int)(num * sign));
}
