#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!new)
		return ;
	l = *lst;
	if (l)
	{
		while (l->next)
			l = l->next;
		l->next = new;
	}
	else
		*lst = new;
}
