#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "minishell.h"
#include "parser_node.h"

t_node *NewNode(enum node_type_e type)
{
    t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->type = type;
	return node;
}

void	AddChildNode(t_node *parent, t_node *child)
{
	t_node *sibling;

	if (!parent || !child)
		return;
	if (!parent->first_child)
		parent->first_child = child;
	else
	{
		sibling = parent->first_child;
		while (sibling->next_sibling)
			sibling = sibling->next_sibling;
		sibling->next_sibling = child;
		child->prev_sibling = sibling;
	}
	parent->children++;
}

void	SetNodeValStr(t_node *node, char *val)
{
	char	*tmp;

	node->val_type = VAL_STR;
	if (!val)
		node->val.str = NULL;
	else
	{
		tmp = malloc(sizeof(char) * (ft_strlen(val) + 1));
		if (!tmp)
			node->val.str = NULL;
		else
		{
			ft_strcpy(tmp, val);
			node->val.str = tmp;
		}
	}
}

void	FreeNodeTree(t_node *node)
{
	t_node *child;
	t_node	*next;

	if (!node)
		return;
	child = node->first_child;
	while (child)
	{
		next = child->next_sibling;
		FreeNodeTree(child);
		child = next;
	}
	if (node->val_type == VAL_STR)
		if (node->val.str)
			free(node->val.str);
	free(node);
}