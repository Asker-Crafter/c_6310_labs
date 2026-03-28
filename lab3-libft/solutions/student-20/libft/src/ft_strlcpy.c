#include "../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	pos;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	pos = 0;
	while (pos < size - 1 && src[pos] != '\0')
	{
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = '\0';
	return (src_len);
}
