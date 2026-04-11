# Лабораторная работа №4 — Студент 20

**Вариант:** 4 (20 % 4 = 0 → вариант 4). Поиск строк по шаблону.

## Формат вызова

```
./search <substr|prefix|suffix|len> <шаблон> [строки...]
```

Если строки не переданы в аргументах — читаются построчно из `stdin`.

Режимы:
- `substr` — строки, содержащие подстроку `<шаблон>`;
- `prefix` — строки, начинающиеся с `<шаблон>`;
- `suffix` — строки, заканчивающиеся на `<шаблон>`;
- `len`    — строки, длина которых равна числу `<шаблон>`.

## Что использовано

- **Указатели на функции:** таблица `table[]` внутри `pick_predicate` связывает имя режима со статическим предикатом типа `t_predicate`.
- **Вариативная функция:** `ft_putstrs_fd(int fd, int count, ...)` — печатает произвольное число строк через `va_list`/`va_start`/`va_arg`/`va_end`. Используется для сообщений об ошибках и справки.
- **argc/argv:** `main` проверяет минимум 3 аргумента, при ошибках пишет в `stderr` и возвращает 1.
- **libft:** `ft_strnstr`, `ft_strncmp`, `ft_strlen`, `ft_atoi`, `ft_strdup`, `ft_strjoin`, `ft_split`, `ft_putstr_fd`, `ft_putchar_fd`, `ft_putendl_fd`.
- **stdio.h/stdlib.h/string.h не подключаются**, используются только `libft.h`, `stdarg.h`, `unistd.h` (для `read`).

## Сборка

```
make
./search substr abc abcde xyz abc123
```

Цели Makefile: `all`, `clean`, `fclean`, `re`. Флаги компиляции: `-Wall -Wextra -Werror`.

## Примеры

```
$ ./search substr abc abcde xyz abc123
abcde
abc123

$ ./search prefix pre prefix pred prelude
prefix
pred
prelude

$ ./search suffix ing running swim jump
running

$ ./search len 3 cat dog bird
cat
dog

$ printf "a\nbb\nccc\n" | ./search len 2
bb
```

## Структура

```
lab4-student-20/
├── inc/libft.h
├── src/main.c
├── libft/libft.a
├── Makefile
└── README.md
```
