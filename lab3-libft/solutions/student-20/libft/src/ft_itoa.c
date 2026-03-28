#include "../inc/libft.h"

static int	digit_count(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits = 1;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				digits;
	unsigned int	num;

	digits = digit_count(n);
	res = (char *)malloc(digits + 1);
	if (res == NULL)
		return (NULL);
	res[digits] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	while (digits > (n < 0 ? 1 : 0))
	{
		res[--digits] = '0' + (char)(num % 10);
		num /= 10;
	}
	return (res);
}
