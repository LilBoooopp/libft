#include "../libft.h"

/**
 * @brief Creates a deep copy of a NULL-terminated array of strings.
 * @param tab Source array to duplicate.
 * @return Newly allocated array with duplicated strings, NULL if tab is NULL
 *         or any allocation fails. On partial failure, all allocated memory
 *         is freed before returning NULL.
 */
char	**ft_tab_dup(char **tab)
{
	char	**dup;
	size_t	len;
	size_t	i;

	if (!tab)
		return (NULL);
	len = ft_chartable_linecount(tab);
	dup = malloc(sizeof(char *) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = ft_strdup(tab[i]);
		if (!dup[i])
		{
			while (i > 0)
				free(dup[--i]);
			return (free(dup), NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

/**
 * @brief Appends a string to a NULL-terminated array, returning a new array.
 * @param tab Existing NULL-terminated array (will be freed). May be NULL.
 * @param str String to append (not duplicated — caller retains ownership of
 *            the pointed-to data, but the pointer is moved into the new array).
 * @return New array containing all previous pointers plus str, NULL on fail.
 * @note Only the array backing is freed, not the strings inside it.
 *       Caller must ensure str is heap-allocated if the array will be freed
 *       with ft_tab_dup or safe_free_tab.
 */
char	**ft_tab_append(char **tab, char *str)
{
	char	**new_tab;
	size_t	len;
	size_t	i;

	len = tab ? ft_chartable_linecount(tab) : 0;
	new_tab = malloc(sizeof(char *) * (len + 2));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = str;
	new_tab[i + 1] = NULL;
	free(tab);
	return (new_tab);
}

/**
 * @brief Searches a NULL-terminated array for the first entry equal to str.
 * @param tab Array of strings to search.
 * @param str String to find.
 * @return Index of the first matching entry, or -1 if not found or either
 *         argument is NULL.
 */
int	ft_tab_contains(char **tab, const char *str)
{
	int	i;

	if (!tab || !str)
		return (-1);
	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Joins all strings of a NULL-terminated array into one string.
 * @param tab Array of strings to join.
 * @param sep Separator inserted between entries (NULL means no separator).
 * @return Newly allocated joined string, or an empty string if tab is NULL.
 *         Returns NULL on allocation failure.
 */
char	*ft_tab_join(char **tab, char *sep)
{
	size_t	n;

	if (!tab)
		return (ft_strdup(""));
	n = ft_chartable_linecount(tab);
	return (ft_strnjoin(tab, n, sep));
}
