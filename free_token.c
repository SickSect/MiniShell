#include "scanner.h"

void        FreeToken(t_token *token)
{
    if (!token->text)
        free(token->text);
    free(token);
}