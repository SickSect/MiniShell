#include "minishell.h"
#include "scaner.h"
#include "syntax.h"
#include "parser.h"
#include "node.h"

static void memory_up(t_node *node)
{
	node->children = 0;
	node->first_child = NULL;
	node->next_sibling = NULL;
	node->prev_sibling = NULL;
}

struct node_s *new_node(enum node_type_e type)
{
    t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->type = type;
	memory_up(node);
	return (node);
}

void add_child_node(struct node_s *parent, struct  node_s *child)
{
	t_node *sibling;

	if (!parent || !child)
		return ;
	if (!parent->first_child)
		parent->first_child = child;
	else
	{
		sibling = parent->first_child;
		while (sibling->next_sibling)
			sibling = sibling->next_sibling;
		child->prev_sibling = sibling;
	}
	parent->children++;
}

void set_node_val_str(t_node *node, char *val)
{
	char	*val_a;

	node->val_type = VAL_STR;
	if (!val)
		node->val.str = NULL;
	else
	{
		val_a = malloc(ft_strlen(val) + 1);
		if (!val_a)
			node->val.str = NULL;
		else
		{
			ft_strcpy(val_a, val);
			node->val.str = val_a;
		}
	}
}

void	free_node_tree(t_node *node)
{
	t_node	*child;
	t_node	*next;

	if (!node)
		return ;
	child = node->first_child;
	while (child)
	{
		next = child->next_sibling;
		free_node_tree(child);
		child = next;
	}
	if (node->val_type == VAL_STR)
	{
		if (node->val.str)
			free(node->val.str);
	}
	free(node);
}