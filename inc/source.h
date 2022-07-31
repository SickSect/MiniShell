#ifndef SOURCE_H
# define SOURCE_H

#define EndOfFile		(-1)
#define ErrorChar		(0)
#define InitSrcPos		(-2)

typedef	struct s_source
{
	char	*buffer;
	long	bufferSize;
	long	currentPos;
} t_source;

char	NextChar(t_source *source);
char	PeekChar(t_source *source);
void	UngetChar(t_source *source);
void	SkipWhiteSpace(t_source *source);

#endif