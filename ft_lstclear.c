#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		cur = *lst;
		next_lst = cur->next;
		ft_lstdelone(cur, del);
		*lst = next_lst;
	}
}
