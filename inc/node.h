#ifndef NODE_H
# define NODE_H

enum e_node_type
{
	NODE_COMMAND,           /* simple command */
	NODE_VAR,               /* variable name (or simply, a word) */
};

enum e_val_type
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

union u_symval
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

typedef struct s_node
{
	enum   e_node_type      type;    /* type of this node */
	enum   e_val_type       val_type; /* type of this node's val field */
	union  u_symval         val;        /* value of this node */
	int                     children;            /* number of child nodes */
	struct node_s           *first_child; /* first child node */
	struct node_s           *next_sibling;
    struct node_s           *prev_sibling;
						/*
						* if this is a child node, keep
						* pointers to prev/next siblings
						*/
}   t_node;

t_node  *new_node(enum e_node_type type);
void    add_child_node(t_node *parent, t_node *new_child);
void    free_node_tree(t_node *node);
void    set_node_val_str(t_node *node, char *val);

#endif