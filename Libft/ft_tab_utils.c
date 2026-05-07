#include "../libft.h"

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

char	*ft_tab_join(char **tab, char *sep)
{
	size_t	n;

	if (!tab)
		return (ft_strdup(""));
	n = ft_chartable_linecount(tab);
	return (ft_strnjoin(tab, n, sep));
}
