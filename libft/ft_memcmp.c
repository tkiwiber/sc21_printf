/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:59:39 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/05 09:20:37 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1_p;
	const char	*str2_p;

	str1_p = (const char *)s1;
	str2_p = (const char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if ((unsigned char)*str1_p != (unsigned char)*str2_p)
			return ((int)((unsigned char)*str1_p - (unsigned char)*str2_p));
		str1_p++;
		str2_p++;
	}
	return (0);
}
