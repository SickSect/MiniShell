#include "lib_utils.h"

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	unsigned int	i;
	char			*str;

	i = start;
	if (start > ft_strlen(s) - 1)
		return (ft_strdup(""));
	if (len < ft_strlen(s) - start)
	{
		str = (char *) malloc((len + 1) * sizeof(char));
		if (str)
		{
			ft_memcpy(str, s + start, len);
			*(str + len) = '\0';
		}
	}
	else
	{
		str = (char *) malloc((ft_strlen(s) - start + 1) * sizeof(char));
		if (str)
		{
			ft_memcpy(str, s + start, ft_strlen(s) - start);
			*(str + ft_strlen(s) - start) = '\0';
		}
	}
	return (str);
}