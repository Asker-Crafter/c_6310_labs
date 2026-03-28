#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	needle_len;
	size_t	pos;

	if (!*little)
		return ((char *)big);
	needle_len = ft_strlen(little);
	pos = 0;
	while (pos + needle_len <= len && big[pos] != '\0')
	{
		if (ft_strncmp(big + pos, little, needle_len) == 0)
			return ((char *)(big + pos));
		pos++;
	}
	return (NULL);
}
