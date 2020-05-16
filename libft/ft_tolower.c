/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:09:22 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/09 14:55:43 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isalpha(c))
	{
		if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
			return (int)(c + 32);
		else
			return (int)(c);
	}
	return (int)(c);
}
