#include "../inc/libft.h"

static void	write_uint(unsigned int n, int fd)
{
	char	ch;

	if (n >= 10)
		write_uint(n / 10, fd);
	ch = '0' + (char)(n % 10);
	write(fd, &ch, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		write_uint((unsigned int)(-n), fd);
	}
	else
		write_uint((unsigned int)n, fd);
}
