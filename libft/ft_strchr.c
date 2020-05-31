/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:32:24 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/23 19:18:45 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str_p;

	str_p = (char *)s;
	while (*str_p != '\0')
	{
		if (*str_p == (unsigned char)c)
			return (str_p);
		str_p++;
	}
	if (*str_p == (unsigned char)c)
		return (str_p);
	else
		return (NULL);
}
