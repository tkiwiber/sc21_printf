/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 11:24:41 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/06 23:13:34 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			uc;
	const unsigned char		*s_ptr;

	uc = (unsigned char)c;
	s_ptr = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*(s_ptr) == uc)
			return ((void *)(s_ptr));
		s_ptr++;
	}
	return (NULL);
}
