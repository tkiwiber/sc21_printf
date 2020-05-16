/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 11:55:08 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/06 12:43:31 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((((unsigned char)c >= 'A' && (unsigned char)c <= 'Z') || \
	((unsigned char)c >= 'a' && (unsigned char)c <= 'z')) && \
	((int)c >= 0 && (int)c <= 255))
		return (1);
	else
		return (0);
}
