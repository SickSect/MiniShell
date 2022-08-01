#include "minishell.h"
#include "source.h"
#include "scanner.h"

t_global *cmdText;

static t_token	*CreateToken(char *str)
{
	t_token	*token;
	char	*newStr;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->textLen = ft_strlen(str);
	newStr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!newStr)
		return (NULL);
	ft_strcpy(newStr, str);
	token->text = newStr;
	
}

static void TokeniseCycle(t_source *source, char tmp)
{
	int		loopFlg;

	loopFlg = 0;
	while (tmp != EndOfFile && loopFlg == 0)
    {
        if (tmp == '\t')
            if (cmdText->tokenIndex > 0)
                loopFlg = 1;
        else if (tmp == '\n')
        {
            if (cmdText > 0)
                UngetChar(source);
            else
                AppendChar(tmp);
			loopFlg = 1;
        }
		else if (tmp = ' ');
		else
			AppendChar(tmp);
		tmp = NextChar(source);
    }
}

static void InitGlobal(t_global *cmdtext)
{
    cmdText->tokenSize = 1024;
    cmdText->tokenIndex = 0;
    cmdText->text = malloc(cmdText->tokenSize);
    if (!cmdText->text)
    {
        errno = ENOMEM;
        return (NULL);
    }
    else
        cmdText->text[0] = '\0';
}

void    AppendChar(char ch)
{
    size_t	i;
    char	*newText;

    i = 0;
    cmdText->text[cmdText->tokenIndex++] = ch;
    if (cmdText->tokenIndex >= cmdText->tokenSize)
    {
        newText = malloc(sizeof(char) * (cmdText->tokenSize + 1024));
        if (!newText)
        {
            errno = ENOMEM;
            return ;
        }
        while (cmdText->text[i])
        {
            newText[i] = cmdText->text[i];
            i++;
        }
		free(cmdText->text);
		cmdText->text = newText;
		cmdText->tokenSize += 1024;
    }
}

t_token *Tokenise(t_source *source)
{
    char    tmp;
	t_token	*token;

    if (!source || !source->buffer || !source->bufferSize)
    {
        errno = ENODATA;
        return (NULL);
    }
    tmp = NextChar(source);
    if (!cmdText->text || tmp == ErrorChar || tmp == EndOfFile)
        return (NULL);
	TokeniseCycle(source, tmp);
	if (cmdText->tokenIndex == 0)
		return (NULL);
	if (cmdText->tokenIndex >= cmdText->tokenSize)
		cmdText->tokenIndex--;
	cmdText->text[cmdText->tokenIndex] = '\0';
	token = CreateToken(cmdText->text);
    token->source = source;
    return (token);
}
