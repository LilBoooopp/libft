/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:18:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/27 10:56:27 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Builds a new string by applying f to each character of s.
 * @param s String to map over.
 * @param f Function called as f(index, s[index]); its return value becomes
 *          the character at that position in the new string.
 * @return Newly allocated result string, or NULL on allocation failure.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	str = malloc(i + 1);
	if (str == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

//int main(void)
//{
//	char s[] = "Hello World";
//	printf("%s\n", ft_strmapi(s, &ft_test));
//}
//
//char ft_test(unsigned int n, char c)
//{
//	if (c >= 97 && c <= 122 && n < 8)
//		c = c - 32;
//	return (c);
//}