/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:49:44 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/02 16:31:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks whether str contains a newline character.
 * @param str String to scan.
 * @return 1 if a '\n' is found, 0 otherwise or if str is NULL.
 */
int	ft_gnl_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}
