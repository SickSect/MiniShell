#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "parser_node.h"
#include "minishell.h"

char	*SearchPath(char *file);
int		DoExecCommand(int argc, char **argv);
int		DoSimpleCommand(struct node_s *node);

#endif