#include "../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		num++;
	}
	return (num);
}
