#ifndef PARSER_H
# define PARSER_H

typedef struct s_source
{
    size_t	str_len;
    char	*spaced_str;
	char	*command;
    char    **splitted_str;
}t_source;

t_source	*parse_str(char *str);

#endif