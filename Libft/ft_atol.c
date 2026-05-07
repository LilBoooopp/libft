/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:25:33 by hdougoud          #+#    #+#             */
/*   Updated: 2025/05/08 15:40:21 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief transforms a string into an integer
 * @param str Pointer to a const str
 * @returns The integer transfromed from ascii
 */
long	ft_atol(const char *str)
{
	int		i;
	int		is_neg;
	long	total;

	i = 0;
	is_neg = 0;
	total = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		total = total * 10 + (str[i++] - '0');
	if (is_neg)
		total = -total;
	return (total);
}
