#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	copy_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		return (ft_strdup(""));
	copy_len = s_len - start;
	if (copy_len > len)
		copy_len = len;
	res = (char *)malloc(copy_len + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s + start, copy_len);
	res[copy_len] = '\0';
	return (res);
}
