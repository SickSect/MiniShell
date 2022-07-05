#ifndef SRC_H
# define SRC_H

# define EOF			(-1)
# define ERR_CH			( 0)
# define INIT_SRC_POS	(-2)

typedef struct s_src
{
    char	*buf; // actualy buffer
    long	b_size; // buffer size
    long	c_pos; //current position 
} t_src;

char			next_ch(t_src*src); // get us next sym
void			unget_ch(t_src *src); 
char			peek_ch(t_src *src); 
void			skip_wsp(t_src *src); // skiping white spaces

#endif