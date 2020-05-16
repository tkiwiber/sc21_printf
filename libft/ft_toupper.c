/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:09:22 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/06 14:24:11 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c))
	{
		if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
			return (int)(c - 32);
		else
			return (int)(c);
	}
	return (int)(c);
}
