#include "../libft.h"

/**
 * @brief Concatenates two strings into a newly allocated string, then frees
 *        both inputs.
 * @param s1 First string (will be freed).
 * @param s2 Second string (will be freed).
 * @return Newly allocated concatenation of s1 and s2, or NULL on alloc fail.
 * @note Both s1 and s2 are freed even if the allocation fails.
 */
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

static size_t	total_len(char **tab, size_t n, size_t seplen)
{
	size_t	total;
	size_t	i;

	total = 0;
	i = 0;
	while (i < n)
		total += ft_strlen(tab[i++]);
	if (n > 1)
		total += seplen * (n - 1);
	return (total);
}

/**
 * @brief Joins n strings from an array into one, separated by sep.
 * @param tab Array of strings to join.
 * @param n   Number of strings to join from tab.
 * @param sep Separator inserted between each string (NULL means no separator).
 * @return Newly allocated joined string, or NULL on alloc fail.
 *         Returns an empty string if n is 0 or tab is NULL.
 */
char	*ft_strnjoin(char **tab, size_t n, char *sep)
{
	char	*result;
	size_t	seplen;
	size_t	len;
	size_t	i;
	size_t	pos;

	if (!tab || n == 0)
		return (ft_strdup(""));
	seplen = sep ? ft_strlen(sep) : 0;
	result = malloc(total_len(tab, n, seplen) + 1);
	if (!result)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < n)
	{
		len = ft_strlen(tab[i]);
		ft_memcpy(result + pos, tab[i], len);
		pos += len;
		if (sep && i + 1 < n)
		{
			ft_memcpy(result + pos, sep, seplen);
			pos += seplen;
		}
		i++;
	}
	result[pos] = '\0';
	return (result);
}
