#include "minishell.h"
#include "node.h"
#include "token.h"

t_node  *new_node(enum e_node_type type)
{
    t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	return (new_node);
}

void	add_child_node(t_node *parent_node, t_node *new_child_node)
{
	t_node *current_node;

	if (!parent_node || !new_child_node)
		return;
	if (!parent_node->first_child)
		parent_node->first_child = new_child_node;
	else
	{
		current_node = parent_node->first_child;
		while (current_node->next_sibling)
			current_node = current_node->next_sibling;
		current_node->next_sibling = new_child_node;
		new_child_node->prev_sibling = current_node;
	}
	parent_node->children++;
}

void	set_node_val_str(t_node *node, char *val)
{
	char	*new_val;

	if (!node)
		return ;
	node->val_type = VAL_STR;
	if (!val)
		node->val.str = NULL;
	else
	{
		new_val = malloc(sizeof(char) * (ft_strlen(val) + 1));
		if (!new_val)
			node->val.str = NULL;
		else
		{
			ft_strcpy(new_val, val);
			node->val.str = new_val;
		}
	}
}

void	free_node_tree(t_node *node)
{
	t_node	*current_node;
	t_node	*next_node;
	if (!node)
		return ;
	current_node = node->first_child;
	while (current_node)
	{
		next_node = current_node->next_sibling;
		free_node_tree(next_node);
		current_node = next_node;
	}
	if (node->val_type == VAL_STR)
	{
		if (node->val.str)
			free(node->val.str);
	}
	free(node);
}