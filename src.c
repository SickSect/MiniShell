#include <errno.h>
#include "minishell.h"
#include "src.h"

char	next_char(t_src *src)
{
    char ch_1;

    if (!src || !src->buf)
    {
        errno = ENODATA;
        return (ERR_CH);
    }
    ch_1 = 0;
    if (src->c_pos == INIT_SRC_POS)
        src->c_pos = -1;
    else
        ch_1 = src->c_pos;
    if (++src->c_pos > src->b_size)
    {
        src->c_pos = src->b_size;
        return (EOF);
    }
}