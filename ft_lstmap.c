#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*ptr;

	ptr = NULL;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (!elem)
		{
			ft_lstclear(&ptr, (*del));
			return (NULL);
		}
		ft_lstadd_back(&ptr, elem);
		lst = lst->next;
	}
	return (ptr);
}
