#ifndef SYNTAX_H
# define SYNTAX_H

# define EOF			(-1)
# define ERRCHAR		( 0)
# define INIT_SRC_POS	(-2)

typedef struct	s_source
{
	char		*string;
	long		s_len;
	long		current_pos;
}				t_source;

char			next_char(struct source_s *src);
void			unget_char(struct source_s *src);
char			peek_char(struct source_s *src);
void			skip_white_spaces(struct source_s *src);

#endif