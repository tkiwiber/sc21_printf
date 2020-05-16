/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 11:53:06 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/06 23:17:08 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dst_p;
	const unsigned char		*src_p;

	dst_p = (unsigned char*)dst;
	src_p = (const unsigned char*)src;
	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	dst_p += len;
	src_p += len;
	while (len-- > 0)
		*--dst_p = *--src_p;
	return (void *)(dst);
}
