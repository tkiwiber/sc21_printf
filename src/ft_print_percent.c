/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 19:03:43 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/20 12:02:24 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_percent(va_list ap, t_mask *mask)
{
	va_list p;
	int w;

	w = mask->width;
	va_copy(p, ap);
	ft_putchar_fd('%', 1);
	return (1);
}
