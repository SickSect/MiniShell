#ifndef PARSER_H
#define PARSER_H

#include "scaner.h"
#include "syntax.h"

struct node_s *parse_simple_command(t_token *tk);

#endif