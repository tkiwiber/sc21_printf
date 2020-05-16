/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 16:11:50 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/09 16:41:04 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		count;

	count = 1;
	node = lst;
	if (node == NULL)
		return (0);
	else
		while (node->next)
		{
			count += 1;
			node = node->next;
		}
	return (count);
}
