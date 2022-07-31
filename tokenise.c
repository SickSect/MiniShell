#include "minishell.h"
#include "source.h"
#include "scanner.h"

t_token *Tokenise(t_source *source)
{
    if (!source || !source->buffer || !source->bufferSize)
    {
        errno = ENODATA;
    }
}
