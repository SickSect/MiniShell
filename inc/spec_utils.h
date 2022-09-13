#ifndef SPEC_UTILS_H
# define SPEC_UTILS_H

#include "pipe.h"
#include "minishell.h"
#include "parser.h"

t_lst	*ft_lst_last_rem(t_lst *lst);
void ft_lst_add_back(t_lst **lst, t_lst *new_node);

#endif