#include "../inc/libft.h"

static size_t	count_tokens(char const *s, char c)
{
	size_t	num;
	int		inside;

	num = 0;
	inside = 0;
	while (*s != '\0')
	{
		if (*s != c && !inside)
		{
			inside = 1;
			num++;
		}
		else if (*s == c)
			inside = 0;
		s++;
	}
	return (num);
}

static void	free_tokens(char **arr, size_t k)
{
	while (k > 0)
	{
		k--;
		free(arr[k]);
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	k;
	size_t	pos;
	size_t	begin;

	if (!s)
		return (NULL);
	arr = (char **)malloc((count_tokens(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	k = 0;
	pos = 0;
	while (k < count_tokens(s, c))
	{
		while (s[pos] == c)
			pos++;
		begin = pos;
		while (s[pos] != '\0' && s[pos] != c)
			pos++;
		arr[k] = ft_substr(s, (unsigned int)begin, pos - begin);
		if (!arr[k])
			return (free_tokens(arr, k), NULL);
		k++;
	}
	arr[k] = NULL;
	return (arr);
}
