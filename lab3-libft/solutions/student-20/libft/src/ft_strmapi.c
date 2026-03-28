#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	size_t			len;
	unsigned int	idx;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (idx < (unsigned int)len)
	{
		res[idx] = f(idx, s[idx]);
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
