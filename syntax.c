#include "minishell.h"
#include "syntax.h"

void	unget_char(t_source *src)
{
	if (src->current_pos < 0)
		return ;
	src->current_pos--;
}

char	next_char(t_source *src)
{
	char	ch;

	if (!src || !src->string)
	{
		errno = (ENODATA);
		return (ERRCHAR);
	}
	ch = 0;
	if (src->current_pos == INIT_SRC_POS)
		src->current_pos = -1;
	else
		ch = src->string[src->current_pos];
	if (++src->current_pos >= src->s_len)
	{
		src->current_pos = src->s_len;
		return (EOF);
	}
	return (src->string[src->current_pos]);
}

char	peek_char(t_source *src)
{
	size_t pos;

	if (!src || !src->string)
	{
		errno = ENODATA;
		return (ERRCHAR);
	}
	pos = src->current_pos;
	if (pos == INIT_SRC_POS)
		pos++;
	pos++;
	if (pos >= src->s_len)
		return (EOF);
	return (src->string[pos]);
}

void	skip_white_spaces(t_source *src)
{
	char	ch;

	if (!src || !src->string)
		return ;
	while (((ch = peek_char(src)) != EOF) && (ch == ' ' || ch == '\t'))
		next_char(src);
}