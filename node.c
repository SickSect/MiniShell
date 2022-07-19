#include "minishell.h"
#include "scaner.h"
#include "syntax.h"
#include "parser.h"
#include "node.h"

struct node_s *new_node(enum node_type_e type)
{
    t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->type = type;
	node->children = 0;
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
	}
}