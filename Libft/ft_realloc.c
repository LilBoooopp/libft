/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:12:17 by cbopp             #+#    #+#             */
/*   Updated: 2025/03/17 10:35:28 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Resizes an allocation by copying up to size bytes to a new buffer.
 * @param ptr  Pointer to the existing allocation (will be freed).
 * @param size Size in bytes of the new allocation.
 * @return Pointer to the new allocation, or NULL on failure.
 * @warning Uses ft_strlcpy internally: only safe for char buffers. Does not
 *          preserve bytes beyond the first null terminator in ptr.
 */
void	*ft_realloc(void *ptr, size_t size)
{
	void	*array;

	array = (void *)malloc(size);
	if (!array)
		return (NULL);
	ft_strlcpy(array, ptr, size);
	free(ptr);
	return (array);
}
