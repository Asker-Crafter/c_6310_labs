#include "../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s);
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s, len + 1);
	return (copy);
}
