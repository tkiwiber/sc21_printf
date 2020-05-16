/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:45:13 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/05 17:04:47 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str_p;
	char	*str_p_res;
	int		flag;

	flag = 0;
	str_p = (char *)s;
	while (*str_p != '\0')
	{
		if (*str_p == (unsigned char)c)
		{
			str_p_res = str_p;
			flag += 1;
		}
		str_p++;
	}
	if (*str_p == (unsigned char)c)
		return (str_p);
	else if (flag)
		return (str_p_res);
	else
		return (NULL);
}
