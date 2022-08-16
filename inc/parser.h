#ifndef PARSER_H
# define PARSER_H

typedef struct s_source
{
    long    str_len;
    long    current_position;
	char	*command;
}t_source;

t_source	*parse_str(char *str);
char        *search_path(char *file);
#endif