#include "../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst_p;
	const unsigned char	*src_p;

	if (!dest || !src)
		return (dest);
	dst_p = (unsigned char *)dest;
	src_p = (const unsigned char *)src;
	if (dst_p > src_p && dst_p < src_p + n)
	{
		while (n > 0)
		{
			n--;
			dst_p[n] = src_p[n];
		}
	}
	else
	{
		while (n-- > 0)
			*dst_p++ = *src_p++;
	}
	return (dest);
}
