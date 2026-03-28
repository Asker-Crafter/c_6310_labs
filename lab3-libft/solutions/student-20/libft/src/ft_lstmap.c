#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*elem;
	void	*mapped;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	res = NULL;
	while (lst != NULL)
	{
		mapped = f(lst->content);
		elem = ft_lstnew(mapped);
		if (elem == NULL)
		{
			del(mapped);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, elem);
		lst = lst->next;
	}
	return (res);
}
