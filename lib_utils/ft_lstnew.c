#include "inc/minishell.h"

t_list	*ft_lstnew(char	*content)
{
	t_list	*elem;

	elem = (t_list *) malloc(sizeof(t_list));
	if (elem)
	{
		elem->content = strdup(content); // ft_strdup
		elem->cmd = NULL;
		elem->next = NULL;
	}
	return (elem);
}
