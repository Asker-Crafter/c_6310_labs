#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	pos;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	pos = 0;
	while (src[pos] != '\0' && dst_len + pos < size - 1)
	{
		dst[dst_len + pos] = src[pos];
		pos++;
	}
	dst[dst_len + pos] = '\0';
	return (dst_len + src_len);
}
