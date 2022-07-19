#ifndef SCANNER_H
#define SCANNER_Hl

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "minishell.h"
#include "syntax.h"

typedef struct token_s
{
	struct source_s *src;       /* source of input */
	int    text_len;            /* length of token text */
	char   *text;               /* token text */
} t_token;

/* the special EOF token, which indicates the end of input */
extern struct token_s eof_token;
struct token_s *tokenize(struct source_s *src);
void free_token(struct token_s *tok);

#endif 