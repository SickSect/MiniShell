#include "inc/minishell.h"

t_lst	*ft_lst_last_rem(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void ft_lst_add_back(t_lst **lst, t_lst *new_node)
{
    if (*lst)
        ft_lst_last_rem(*lst)->next = new_node;
    else
        *lst = new_node;
}