#include "../libft.h"

/**
 * @brief Checks whether s starts with the given prefix.
 * @param s      String to test.
 * @param prefix Prefix to look for.
 * @return 1 if s starts with prefix, 0 otherwise.
 *         Returns 0 if either argument is NULL.
 */
int	ft_str_startswith(const char *s, const char *prefix)
{
	size_t	plen;

	if (!s || !prefix)
		return (0);
	plen = ft_strlen(prefix);
	return (ft_strncmp(s, prefix, plen) == 0);
}

/**
 * @brief Checks whether s ends with the given suffix.
 * @param s      String to test.
 * @param suffix Suffix to look for.
 * @return 1 if s ends with suffix, 0 otherwise.
 *         Returns 0 if either argument is NULL or suffix is longer than s.
 */
int	ft_str_endswith(const char *s, const char *suffix)
{
	size_t	slen;
	size_t	suflen;

	if (!s || !suffix)
		return (0);
	slen = ft_strlen(s);
	suflen = ft_strlen(suffix);
	if (suflen > slen)
		return (0);
	return (ft_strncmp(s + slen - suflen, suffix, suflen) == 0);
}

/**
 * @brief Reverses a string in place.
 * @param s String to reverse.
 * @return Pointer to the same string, now reversed.
 *         Returns NULL if s is NULL.
 */
char	*ft_strrev(char *s)
{
	size_t	len;
	size_t	i;
	char	tmp;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
		i++;
	}
	return (s);
}

/**
 * @brief Counts occurrences of character c in string s.
 * @param s String to search.
 * @param c Character to count.
 * @return Number of times c appears in s.
 */
size_t	ft_count_char(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s++ == c)
			count++;
	}
	return (count);
}
