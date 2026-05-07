/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:45:42 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/27 10:56:14 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Applies f to each character of s, passing its index and address.
 * @param s String to iterate over.
 * @param f Function called as f(index, &s[index]) for each character.
 * @note s is modified in place if f writes through the char pointer.
 *       Does nothing if s is NULL.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

//int main(void)
//{
//	char s[] = "Hello World";
//	ft_striteri(s, &ft_test);
//}
//
//oid ft_test(unsigned int n, char *c)
//{
//	if (*c >= 97 && *c <= 122 && n < 8)
//		*c -=32;
//}