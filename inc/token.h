#ifndef TOKEN_H
# define TOKEN_H

#include "parser.h"
#include "minishell.h"

#define Error_char (0)
#define End_of_file (-1)
#define Init_position (-2)

typedef struct s_token
{
    t_source *src;
    char *text;
    int text_len;
} t_token;

typedef struct s_scan_str
{
    char    current_char;
    char    next_char;
    int     current_index;
    int     current_size;
    int     iter_a;
    int     qoute;
    char    *scan_str;
} t_scan_str;

t_token	*tokenize(t_source *src);
void	free_token(t_token *tok);
char    get_next_char(t_source *src);
void    add_char(char ch, t_scan_str *scan);
char    peek_char(t_source *src);
void    char_back(t_source *src);
size_t  find_closing_quote(char *data);
int     quote_case(t_scan_str *scan, t_source *src);
int     brace_case(t_scan_str *scan, t_source *src);
int     dollar_case(t_scan_str *scan, t_source *src);
int     void_case(t_scan_str *scan, t_source *src);
#endif