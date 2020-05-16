/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:44:08 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/12 15:42:23 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dst_p;
	const unsigned char		*src_p;
	size_t					i;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned const char *)src;
	i = 0;
	while (i < n && src_p[i] != (unsigned char)c)
	{
		dst_p[i] = src_p[i];
		i += 1;
	}
	if (i == n)
		return (NULL);
	else
	{
		dst_p[i] = src_p[i];
		i++;
		return (&dst_p[i]);
	}
}
