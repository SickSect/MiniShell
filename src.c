#include "minishell.h"
#include "source.h"


char    *PeekChar(t_source *source)
{
    long    position;

    if (!source || !source->buffer)
    {
        errno = ENODATA;
        return (ErrorChar);
    }
    position = source->currentPos;
    if (position == InitSrcPos)
        position++;
    position++;
    if (position >= source->bufferSize)
        return (EndOfFile);
    return (source->buffer[position]);
}

char    *NextChar(t_source *source)
{
    char    *tmp;

    if (!source || !source->buffer)
    {
        errno = ENODATA;
        return (ErrorChar);
    }
    tmp = 0;
    if (source->currentPos == InitSrcPos)
        source->currentPos = -1;
    else
        tmp = source->buffer[source->currentPos];
    if (++source->currentPos >= source->bufferSize)
    {
        source->currentPos = source->bufferSize;
        return (EndOfFile);
    }
    return (source->buffer[source->currentPos]);
}

void    UngetChar(t_source *source)
{
    if (source->currentPos < 0)
        return;
    source->currentPos--;    
}

void    SkipWhiteSpace(t_source *source)
{
    char    tmp;

    if (!source || !source->buffer)
        return ;
    while (((tmp = PeekChar(source)) != EndOfFile) && (tmp = ' ' || tmp == '\t'))
        NextChar(source);
}