#include "../libft.h"

/**
 * @brief Allocates a copy of size bytes starting at src.
 * @param src  Pointer to the source memory region.
 * @param size Number of bytes to copy.
 * @return Pointer to the newly allocated copy, or NULL if src is NULL or the
 *         allocation fails.
 */
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
