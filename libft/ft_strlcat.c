/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 09:23:01 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/14 18:00:32 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	char		*dest_p;
	size_t		dest_len;
	size_t		i;

	dest_len = ft_strlen(dest);
	dest_p = (char *)dest;
	if (!*src)
		return (int)(dest_len);
	else if (destsize < dest_len + 1)
		return (int)(destsize + ft_strlen(src));
	i = 0;
	while (destsize > dest_len + 1 && i < destsize - dest_len - 1 \
	&& (unsigned char)src[i] != '\0')
	{
		dest_p[dest_len + i] = src[i];
		i++;
	}
	dest_p[dest_len + i] = '\0';
	return (int)(dest_len + ft_strlen(src));
}
