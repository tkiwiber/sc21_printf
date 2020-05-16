/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:09:00 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/07 15:41:55 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] != '\0' && ft_strchr(set, s1[beg]) != NULL)
		beg++;
	end = ft_strlen(s1);
	if (end && end > beg)
		while (end > beg && ft_strchr(set, s1[end]) != NULL)
			end--;
	end++;
	str = (char*)malloc(sizeof(char) * (end - beg + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + beg, end - beg + 1);
	str[end - beg + 1] = '\0';
	return (str);
}
