#include "src.h"

void	unget_ch(t_src *src)
{
    if (src->c_pos < 0)
        return ;
    src->c_pos--;
}

char	next_ch(t_src *src)
{
    char	ch;

    if (!src || !src->buf)
	{
		errno = ENODATA; // error if our buf is empty
		return (ERR_CH); // return 0 , it is error of NO DATA
	}
	ch = 0;
	if (src->c_pos = INIT_SRC_POS)
		src->c_pos = -1; // if our c_pos = -2 we make it -1
	else
		ch = src->buf[src->c_pos]; // otherwise we put sym frop c_pos buf into ch value
	if (++src->c_pos == src->b_size) // we take next sym and if it is END OF FILE
	{
		src->c_pos = src->b_size; // we change out c_pos
		return (EOF); // and return EOF (it is -1) that means we finish reading
	}
	return (src->buf[src->c_pos]); // otherwise we return new sym
}

char	peek_ch(t_src *src)
{
	long	pos; // position

	if (!src || !src->buf)
	{
		errno = ENODATA; // error if our buf is empty
		return (ERR_CH); // return 0 , it is error of NO DATA
	}
	pos = src->c_pos; // our pos value = current position
	if (pos = INIT_SRC_POS) // if out position = -2 we make it -1
		pos++;
	pos++; //and now make it 1 or just next step
	if (pos >= src->b_size) // if out pos = EOF we return EOF
		return (EOF);
	return (src->buf[pos]); // otherwise we return sym on pos value
}

void	skip_wsp(t_src *src)
{
	char	ch;

	if (!src || !src->buf) // check for NODATA
		return ;
	while (((ch = peek_ch(src)) != EOF) && (ch == ' ' || ch == '\t')) // check sym if it EOF or \r or ' '
		next_ch(src);
}