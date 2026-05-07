#include "../libft.h"

char	*ft_ltoa(long n)
{
	unsigned long	uval;
	char		buf[22];
	int		i;
	int		neg;
	char		*str;

	neg = (n < 0);
	uval = neg ? -(unsigned long)n : (unsigned long)n;
	i = 20;
	buf[21] = '\0';
	if (uval == 0)
		buf[i--] = '0';
	while (uval > 0)
	{
		buf[i--] = '0' + (uval % 10);
		uval /= 10;
	}
	if (neg)
		buf[i--] = '-';
	str = ft_strdup(buf + i + 1);
	return (str);
}
