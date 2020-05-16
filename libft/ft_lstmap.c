/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:56:30 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/15 16:45:44 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	if (!(lst && f))
		return (NULL);
	new_list = NULL;
	while (lst)
		if (!(new_element = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new_list, del);
			free(new_list);
			new_list = NULL;
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&new_list, new_element);
			lst = lst->next;
		}
	return (new_list);
}
