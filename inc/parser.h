#ifndef PARSER_H
# define PARSER_H

typedef struct s_source
{
    size_t	str_len;
    char	*spaced_str;
	char	*cmd;
    char    **splitted_str;
    char    *cmd_path;
}t_source;

t_source	*parse_str(char *str);
char        *search_path(char *file);
#endif