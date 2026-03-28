#include "../inc/libft.h"

static int	char_in_set(char c, char const *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] != '\0' && char_in_set(s1[begin], set))
		begin++;
	while (end > begin && char_in_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, (unsigned int)begin, end - begin));
}
