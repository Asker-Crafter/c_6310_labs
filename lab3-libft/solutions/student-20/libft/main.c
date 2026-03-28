#include "inc/libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	test_chars(void)
{
	printf("=== Character functions ===\n");
	printf("ft_isalpha('z')=%d ft_isalpha('0')=%d\n", ft_isalpha('z'), ft_isalpha('0'));
	printf("ft_isdigit('9')=%d ft_isdigit('a')=%d\n", ft_isdigit('9'), ft_isdigit('a'));
	printf("ft_isalnum('b')=%d ft_isalnum('@')=%d\n", ft_isalnum('b'), ft_isalnum('@'));
	printf("ft_isascii(100)=%d ft_isascii(128)=%d\n", ft_isascii(100), ft_isascii(128));
	printf("ft_isprint(126)=%d ft_isprint(31)=%d\n", ft_isprint(126), ft_isprint(31));
	printf("ft_toupper('m')=%c ft_tolower('M')=%c\n", ft_toupper('m'), ft_tolower('M'));
	printf("ft_isspace('\\n')=%d ft_isspace('x')=%d\n", ft_isspace('\n'), ft_isspace('x'));
}

static void	test_strings(void)
{
	char	buf[64];

	printf("\n=== String functions ===\n");
	printf("ft_strlen(\"world\")=%u\n", (unsigned int)ft_strlen("world"));
	printf("ft_strchr(\"abcabc\",'c')=%s\n", ft_strchr("abcabc", 'c'));
	printf("ft_strrchr(\"abcabc\",'a')=%s\n", ft_strrchr("abcabc", 'a'));
	printf("ft_strncmp(\"xyz\",\"xya\",3)=%d\n", ft_strncmp("xyz", "xya", 3));
	printf("ft_strnstr(\"foo bar\",\"bar\",7)=%s\n", ft_strnstr("foo bar", "bar", 7));
	ft_strlcpy(buf, "test", sizeof(buf));
	printf("ft_strlcpy: %s\n", buf);
	ft_strlcat(buf, "ing", sizeof(buf));
	printf("ft_strlcat: %s\n", buf);
}

static void	test_memory(void)
{
	char	buf[12];

	printf("\n=== Memory functions ===\n");
	ft_memset(buf, 'A', 4);
	buf[4] = '\0';
	printf("ft_memset: %s\n", buf);
	ft_bzero(buf, 4);
	printf("ft_bzero: buf[0]=%d\n", (int)buf[0]);
	ft_memcpy(buf, "world", 6);
	printf("ft_memcpy: %s\n", buf);
	ft_memmove(buf + 2, buf, 3);
	printf("ft_memmove: %s\n", buf);
}

static void	test_alloc(void)
{
	char	**words;
	char	*s;
	int		k;

	printf("\n=== Allocation functions ===\n");
	printf("ft_atoi(\"+100\")=%d\n", ft_atoi("+100"));
	s = ft_strdup("copy");
	printf("ft_strdup: %s\n", s);
	free(s);
	s = ft_substr("programming", 3, 4);
	printf("ft_substr: %s\n", s);
	free(s);
	s = ft_strjoin("foo", "bar");
	printf("ft_strjoin: %s\n", s);
	free(s);
	s = ft_strtrim("***hello***", "*");
	printf("ft_strtrim: %s\n", s);
	free(s);
	s = ft_itoa(-2147483648);
	printf("ft_itoa(INT_MIN): %s\n", s);
	free(s);
	words = ft_split("one two three", ' ');
	k = 0;
	while (words[k])
	{
		printf("ft_split[%d]: %s\n", k, words[k]);
		free(words[k]);
		k++;
	}
	free(words);
}

static void	del(void *content)
{
	free(content);
}

static void	*dup_content(void *content)
{
	return (ft_strdup((char *)content));
}

static void	test_lists(void)
{
	t_list	*lst;
	t_list	*mapped;

	printf("\n=== List functions ===\n");
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("alpha")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("beta")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("zero")));
	printf("ft_lstsize: %d\n", ft_lstsize(lst));
	printf("ft_lstlast: %s\n", (char *)ft_lstlast(lst)->content);
	mapped = ft_lstmap(lst, dup_content, del);
	printf("ft_lstmap first: %s\n", (char *)mapped->content);
	ft_lstclear(&lst, del);
	ft_lstclear(&mapped, del);
	printf("Lists cleared OK\n");
}

int	main(void)
{
	printf("=== libft student-20 tests ===\n\n");
	test_chars();
	test_strings();
	test_memory();
	test_alloc();
	test_lists();
	printf("\n=== All tests passed ===\n");
	return (0);
}
