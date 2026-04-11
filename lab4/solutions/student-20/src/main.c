#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

/*
** Лабораторная работа №4, вариант 4: поиск строк по шаблону.
** Студент: 20.
**
** В программе используются:
**   - указатели на функции (таблица предикатов);
**   - вариативная функция ft_putstrs_fd для вывода нескольких строк;
**   - разбор argc/argv и чтение stdin через read + ft_split;
**   - libft вместо <stdio.h>/<stdlib.h>/<string.h>.
*/

typedef int	(*t_predicate)(const char *line, const char *tpl, int len_n);

typedef struct s_entry
{
	const char		*mode;
	t_predicate		pred;
}	t_entry;

/* ------------- Предикаты поиска ------------- */

static int	p_substr(const char *line, const char *tpl, int len_n)
{
	(void)len_n;
	if (ft_strnstr(line, tpl, ft_strlen(line)))
		return (1);
	return (0);
}

static int	p_prefix(const char *line, const char *tpl, int len_n)
{
	size_t	tl;

	(void)len_n;
	tl = ft_strlen(tpl);
	if (ft_strlen(line) < tl)
		return (0);
	if (ft_strncmp(line, tpl, tl) == 0)
		return (1);
	return (0);
}

static int	p_suffix(const char *line, const char *tpl, int len_n)
{
	size_t	ll;
	size_t	tl;

	(void)len_n;
	ll = ft_strlen(line);
	tl = ft_strlen(tpl);
	if (ll < tl)
		return (0);
	if (ft_strncmp(line + (ll - tl), tpl, tl) == 0)
		return (1);
	return (0);
}

static int	p_len(const char *line, const char *tpl, int len_n)
{
	(void)tpl;
	if ((int)ft_strlen(line) == len_n)
		return (1);
	return (0);
}

/* ------------- Выбор режима через таблицу указателей ------------- */

static t_predicate	pick_predicate(const char *mode)
{
	static const t_entry	table[] = {
		{"substr", p_substr},
		{"prefix", p_prefix},
		{"suffix", p_suffix},
		{"len",    p_len},
		{NULL,     NULL}
	};
	int	i;

	i = 0;
	while (table[i].mode)
	{
		if (ft_strncmp(table[i].mode, mode, ft_strlen(table[i].mode) + 1) == 0)
			return (table[i].pred);
		i++;
	}
	return (NULL);
}

/* ------------- Вариативная функция ------------- */

/*
** ft_putstrs_fd — печатает count строк подряд в указанный fd.
** Используется для сообщений об ошибках / справки.
** Демонстрирует va_list / va_start / va_arg / va_end.
*/
static void	ft_putstrs_fd(int fd, int count, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, count);
	i = 0;
	while (i < count)
	{
		ft_putstr_fd(va_arg(ap, char *), fd);
		i++;
	}
	va_end(ap);
	ft_putchar_fd('\n', fd);
}

/* ------------- Вспомогательные функции ------------- */

static void	try_emit(t_predicate pred, const char *tpl, int n, char *line)
{
	if (pred(line, tpl, n))
		ft_putendl_fd(line, 1);
}

static void	release(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*slurp_stdin(void)
{
	char	buf[2048];
	char	*acc;
	char	*merged;
	ssize_t	r;

	acc = ft_strdup("");
	if (!acc)
		return (NULL);
	while (1)
	{
		r = read(0, buf, sizeof(buf) - 1);
		if (r <= 0)
			break ;
		buf[r] = '\0';
		merged = ft_strjoin(acc, buf);
		free(acc);
		if (!merged)
			return (NULL);
		acc = merged;
	}
	if (r < 0)
	{
		free(acc);
		return (NULL);
	}
	return (acc);
}

static int	scan_stdin(t_predicate pred, const char *tpl, int n)
{
	char	*data;
	char	**lines;
	int		i;

	data = slurp_stdin();
	if (!data)
		return (1);
	lines = ft_split(data, '\n');
	free(data);
	if (!lines)
		return (1);
	i = 0;
	while (lines[i])
	{
		try_emit(pred, tpl, n, lines[i]);
		i++;
	}
	release(lines);
	return (0);
}

/* ------------- main ------------- */

int	main(int argc, char **argv)
{
	t_predicate	pred;
	int			n;
	int			i;

	if (argc < 3)
	{
		ft_putstrs_fd(2, 2, "Usage: ",
			"./search <substr|prefix|suffix|len> <pattern> [strings...]");
		return (1);
	}
	pred = pick_predicate(argv[1]);
	if (!pred)
	{
		ft_putstrs_fd(2, 3, "Error: unknown mode '", argv[1], "'");
		return (1);
	}
	n = 0;
	if (ft_strncmp(argv[1], "len", 4) == 0)
		n = ft_atoi(argv[2]);
	if (argc > 3)
	{
		i = 3;
		while (i < argc)
		{
			try_emit(pred, argv[2], n, argv[i]);
			i++;
		}
		return (0);
	}
	return (scan_stdin(pred, argv[2], n));
}
