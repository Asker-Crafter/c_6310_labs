#include "../inc/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			pos;

	ptr = (unsigned char *)s;
	pos = 0;
	while (pos < n)
	{
		ptr[pos] = (unsigned char)c;
		pos++;
	}
	return (s);
}
