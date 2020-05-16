/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:09:16 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/05 19:09:12 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	int			flag;

	i = 0;
	if (*needle == '\0')
		return (char*)(haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		flag = 1;
		while (needle[j] != '\0' && ((i + j) < len))
		{
			if (haystack[i + j] != needle[j])
			{
				flag = 0;
				break ;
			}
			j++;
		}
		if (flag && j == ft_strlen(needle))
			return (char*)(haystack + (char)i);
		i++;
	}
	return (NULL);
}
