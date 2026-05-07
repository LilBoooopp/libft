/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:33:03 by hdougoud          #+#    #+#             */
/*   Updated: 2024/11/27 10:55:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Builds a new list by applying f to each node's content.
 * @param lst List to iterate over.
 * @param f   Function applied to each content; its return value becomes the
 *            new node's content.
 * @param del Function used to free content if an allocation fails mid-way.
 * @return Pointer to the first node of the new list, or NULL on alloc fail.
 *         On failure the partial list is cleared via ft_lstclear before
 *         returning NULL.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*flst;
	t_list	*bflst;

	bflst = NULL;
	while (lst)
	{
		flst = malloc(sizeof(t_list));
		if (flst == NULL)
		{
			ft_lstclear(&bflst, del);
			return (NULL);
		}
		flst->content = f(lst->content);
		flst->next = NULL;
		ft_lstadd_back(&bflst, flst);
		lst = lst->next;
	}
	return (bflst);
}
