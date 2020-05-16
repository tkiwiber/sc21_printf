/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:44:31 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/08 19:41:04 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;

	str = (void *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
