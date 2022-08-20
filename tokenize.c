#include "token.h"
#include "parser.h"
#include "minishell.h"

static int  token_validation(t_source *src)
{
    if (!src || !src->command || !src->str_len)
    {
        errno = ENODATA;
        return (-1);
    }
    return 1;
}

static int tokenize_cycle(t_token *tok, t_source *src, t_scan_str *scan, int endloop)
{
	while (scan->current_char != End_of_file)
	{
		if (scan->current_char == '"' || scan->current_char == '\'' || scan->current_char == '`')
		{
			add_char()
		}
		scan->current_char = get_next_char(src);
	}
}

t_token *tokenize(t_source *src)
{
	t_token		*tok;
	t_scan_str	*scan;
	int	endloop;

	endloop = 0;
	if (!token_validation(src))
		return (NULL);
	scan->current_size = 1024;
	scan->current_index = 0;
	scan->scan_str = malloc(sizeof(char) * (scan->current_size));
	if (!scan->scan_str)
	{
		errno = ENODATA;
		return NULL;
	}
	scan->scan_str[0] = '\0';
	scan->current_char = get_next_char(src);
	if (scan->current_char == Error_char || scan->current_char == End_of_file)
		return (NULL);
	tok->text_len = src->str_len;
	tokenize_cycle(tok, src, scan, endloop);
}