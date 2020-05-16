/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 10:02:18 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/08 20:00:32 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	ptr = (void *)malloc(sizeof(char) * size * count);
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(ptr, count * size * (sizeof(char)));
	return (ptr);
}
