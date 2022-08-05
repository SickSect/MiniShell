#ifndef SCANNER_H
# define SCANNER_H

#include "minishell.h"
#include "source.h"
#include "scanner.h"
#include "source.h"

enum node_type_e
{
	NODE_COMMAND,           /* simple command */
	NODE_VAR,               /* variable name (or simply, a word) */
};

enum val_type_e
{
	VAL_SINT = 1,       /* signed int */
	VAL_UINT,           /* unsigned int */
	VAL_SLLONG,         /* signed long long */
	VAL_ULLONG,         /* unsigned long long */
	VAL_FLOAT,          /* floating point */
	VAL_LDOUBLE,        /* long double */
	VAL_CHR,            /* char */
	VAL_STR,            /* str (char pointer) */
};

union symval_u
{
	long               sint;
	unsigned long      uint;
	long long          sllong;
	unsigned long long ullong;
	double             sfloat;
	long double        ldouble;
	char               chr;
	char              *str;
};

typedef struct node_s
{
	enum   node_type_e type;    /* type of this node */
	enum   val_type_e val_type; /* type of this node's val field */
	union  symval_u val;        /* value of this node */
	int    children;            /* number of child nodes */
	struct node_s *first_child; /* first child node */
	struct node_s *next_sibling, *prev_sibling;
						/*
						* if this is a child node, keep
						* pointers to prev/next siblings
						*/
} t_node;

struct	node_s *ParseSimpleCmd(t_token *token);
void	AddChildNode(t_node *parent, t_node *child);
void	FreeNodeTree(t_node *node);
void	SetNodeValStr(t_node *node, char *val);

#endif