#include "../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n && (s1[pos] != '\0' || s2[pos] != '\0'))
	{
		if ((unsigned char)s1[pos] != (unsigned char)s2[pos])
			return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
		pos++;
	}
	return (0);
}
