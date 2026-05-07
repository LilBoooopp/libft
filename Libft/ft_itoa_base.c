#include "../libft.h"

static size_t	fill_buf(unsigned long val, int base, char *buf)
{
	static const char	*hex = "0123456789abcdef";
	size_t			i;

	i = 63;
	buf[64] = '\0';
	if (val == 0)
		buf[i--] = '0';
	while (val > 0)
	{
		buf[i--] = hex[val % base];
		val /= base;
	}
	return (i + 1);
}

char	*ft_itoa_base(long n, int base)
{
	char		buf[65];
	size_t		start;
	int		neg;
	unsigned long	uval;

	if (base < 2 || base > 16)
		return (NULL);
	neg = (n < 0 && base == 10);
	uval = neg ? -(unsigned long)n : (unsigned long)n;
	start = fill_buf(uval, base, buf);
	if (neg)
		buf[--start] = '-';
	return (ft_strdup(buf + start));
}

static int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	result;
	int	neg;
	int	digit;

	if (!str || base < 2 || base > 16)
		return (0);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	neg = 0;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = 0;
	while (*str)
	{
		digit = char_to_digit(*str);
		if (digit < 0 || digit >= base)
			break ;
		result = result * base + digit;
		str++;
	}
	return (neg ? -result : result);
}
