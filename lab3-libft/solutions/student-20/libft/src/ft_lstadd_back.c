#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*tail;

	if (lst == NULL || node == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	tail = ft_lstlast(*lst);
	tail->next = node;
}
