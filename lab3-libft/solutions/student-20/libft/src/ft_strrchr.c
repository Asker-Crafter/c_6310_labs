#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	const char	*found;

	ch = (char)c;
	found = NULL;
	while (*s != '\0')
	{
		if (*s == ch)
			found = s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return ((char *)found);
}
