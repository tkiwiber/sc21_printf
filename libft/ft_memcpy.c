/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:14:16 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/12 11:57:54 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*dst_p;
	unsigned const char		*src_p;

	if (!dst && !src)
		return (dst);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	while (n-- > 0)
		*(dst_p++) = *(src_p++);
	return (void *)(dst);
}
