/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 19:03:43 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/17 19:30:49 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_percent(va_list ap)
{
	va_list p;

	va_copy(p, ap);
	ft_putchar_fd('%', 1);
	return (1);
}
