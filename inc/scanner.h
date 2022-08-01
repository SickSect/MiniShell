typedef struct s_token
{
    t_source    *source;
    int         textLen;
    char        *text;

} t_token;

typedef struct s_global
{
    char    *text;
    int     tokenSize;
    int     tokenIndex;
} t_global;

t_token     *Tokenize(t_source *source);
void        FreeToken(t_token *token);
