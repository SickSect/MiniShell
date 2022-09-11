#include "inc/minishell.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_mod(long n, int len, int neg)
{
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) *(len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		neg = -1;
		n = -n;
	}
	str[len] = '\0';
	while (--len)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	if (neg < 0)
		str[0] = '-';
	else
		str[0] = '0' + (n % 10);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	long	nb;
	int		len;

	len = ft_len(n);
	nb = n;
	neg = 0;
	str = ft_mod(nb, len, neg);
	if (!str)
		return (NULL);
	return (str);
}