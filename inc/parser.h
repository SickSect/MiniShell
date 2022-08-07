#ifndef PARSER_H
# define PARSER_H

typedef struct s_source
{
    size_t	str_len;
    char	*buf_str;
	char	**substr_arg;
}t_source;

t_source	*parse_str(char *str);

#endif