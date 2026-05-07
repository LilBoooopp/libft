#include "../libft.h"

void	*ft_memdup(const void *src, size_t size)
{
	void	*dup;

	if (!src)
		return (NULL);
	dup = malloc(size);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, src, size);
	return (dup);
}
