/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:42:32 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/10 22:55:37 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (!(lst && del))
		return ;
	next_node = NULL;
	while (*lst)
	{
		next_node = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		(*lst) = next_node;
	}
	free(*lst);
	lst = NULL;
}
