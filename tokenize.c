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

static int	quote_checker(char ch)
{
	if (ch == '"' || ch == '\'' || ch == '`')
		return (1);
	else
		return (0);
}

static int	quote_case()
{

}

static int tokenize_cycle(char *scan_str, t_source *src, t_token *tok, int *current_size)
{
	int		endloop;
	int		i;
	char	next_char;
	char	current_char;
	int		current_index;

	current_index = 0;
	endloop = 0;
	while (current_char = get_next_char(src) != End_of_file)
	{
		if (quote_checker(current_char) == 1)
		{
			add_char(scan_str, current_char, &current_index, current_size);
			i = find_closing_quote(src->command);
		}
		if (!i)
		{
			print_str_with_char("error missing closing quote", current_char, stderr);
			src->current_position = src->str_len;
			return (NULL);
		}
		while (i--)
			add_char(get_next_char(src));
	}
}

t_token *tokenize(t_source *src)
{
	//change on struct t_scan_str!!!!!!
    char	*scan_str;
	t_token	*tok;
	int		current_size;

	if (!token_validation(src))
		return (NULL);
	scan_str = NULL;
	scan_str = malloc(sizeof(char) * (1024));
	if (!scan_str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	scan_str[0] = '\0';
	current_size = 1024;
	tokenize_cycle(scan_str, src, tok, &current_size);
}