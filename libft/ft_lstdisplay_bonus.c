/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdisplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 13:23:23 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/10 23:31:11 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listdisplay(t_list *begin_list)
{
	while (begin_list)
	{
		write(1, begin_list->content, ft_strlen(begin_list->content));
		write(1, "\n", 2);
		begin_list = begin_list->next;
	}
}
