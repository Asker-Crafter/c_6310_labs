#include "../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst_p;
	const unsigned char	*src_p;
	size_t				pos;

	if (!dest || !src)
		return (dest);
	dst_p = (unsigned char *)dest;
	src_p = (const unsigned char *)src;
	pos = 0;
	while (pos < n)
	{
		dst_p[pos] = src_p[pos];
		pos++;
	}
	return (dest);
}
