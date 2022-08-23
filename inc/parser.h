#ifndef PARSER_H
# define PARSER_H

typedef struct s_source
{
    long    str_len;
    long    current_position;
	char	*command;
}t_source;

char        *search_path(char *file);
#endif