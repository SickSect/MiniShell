#include "token.h"
#include "parser.h"
#include "minishell.h"

static t_token *create_token(char *str)
{
	t_token	*tok;
	int		i;

	i = 0;
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->text_len = ft_strlen(str);
	tok->text = malloc(sizeof(char) * (tok->text_len + 1));
	if (!tok->text)
	{
		free(tok);
		return (NULL);
	}
	while (str[i])
	{
		tok->text[i] = str[i];
		i++;
	}
	tok->text[i] = '\0';
	return (tok);
}

static int  token_validation(t_source *src)
{
    if (!src || !src->command || !src->str_len)
    {
        errno = ENODATA;
        return (-1);
    }
    return 1;
}

static int tokenize_cycle(t_scan_str *scan, t_source *src)
{
	int	endloop;

	endloop = 0;
	while (scan->current_char != End_of_file && endloop == 0)
	{
		if (scan->current_char == '"' || scan->current_char == '\''
			|| scan->current_char == '`')
			endloop = quote_case(scan, src);
		else if (scan->current_char == '\\')
			endloop = brace_case(scan, src);
		else if (scan->current_char == '$')
			endloop = dollar_case(scan, src);
		else if (scan->current_char == ' ' || scan->current_char == '\t'
			|| scan->current_char == '\n')
			endloop = void_case(scan, src);
		else
			add_char(scan->current_char, scan);
		if (endloop)
			break;
		scan->current_char = get_next_char(src);
	}
	return (endloop);
}

static t_token *tokenize_post_check(t_scan_str *scan, t_source *src)
{
	t_token *new_token;
	if (scan->current_index == 0)
		return (NULL);
	if (scan->current_index >= scan->current_size)
		scan->current_index--;
	scan->scan_str[scan->current_index] = '\0';
	new_token = create_token(scan->scan_str);
	new_token->src = src;
	return (new_token);
}

t_token *tokenize(t_source *src)
{
	t_token		*tok;
	t_scan_str	*scan;
	int	endloop;

	if (!token_validation(src))
		return (NULL);
	scan = malloc(sizeof(t_scan_str));
	scan->current_size = 1024;
	scan->current_index = 0;
	scan->scan_str = malloc(sizeof(char) * (scan->current_size + 1));
	if (!scan->scan_str)
	{
		errno = ENODATA;
		return NULL;
	}
	scan->scan_str[0] = '\0';
	scan->current_char = get_next_char(src);
	if (scan->current_char == Error_char || scan->current_char == End_of_file)
		return (NULL);
	tokenize_cycle(scan, src);
	tok = tokenize_post_check(scan, src);
	return (tok);
}