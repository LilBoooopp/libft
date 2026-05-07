#include "../libft.h"

int	ft_str_startswith(const char *s, const char *prefix)
{
	size_t	plen;

	if (!s || !prefix)
		return (0);
	plen = ft_strlen(prefix);
	return (ft_strncmp(s, prefix, plen) == 0);
}

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
