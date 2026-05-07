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

/**
 * @brief Converts a long integer to a string in the given base.
 * @param n    Integer to convert.
 * @param base Numeric base between 2 and 16 inclusive.
 * @return Newly allocated string representation, or NULL if base is invalid
 *         or allocation fails.
 * @note Negative sign is only prepended for base 10.
 *       Digits a–f are lowercase.
 */
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

/**
 * @brief Parses a string as an integer in the given base.
 * @param str  String to parse. Leading whitespace is skipped.
 *             An optional leading '+' or '-' is accepted.
 * @param base Numeric base between 2 and 16 inclusive.
 * @return Parsed integer value, or 0 if str is NULL or base is invalid.
 * @note Parsing stops at the first character not valid in the given base.
 *       Accepts both upper and lower case hex digits (a–f / A–F).
 */
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
