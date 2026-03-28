#include "../inc/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *node)
{
	if (lst == NULL || node == NULL)
		return ;
	node->next = *lst;
	*lst = node;
}
