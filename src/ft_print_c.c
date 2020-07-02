/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:32:57 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/02 12:48:45 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_print_c_get_strout(va_list ap, t_mask *mask)
{
	unsigned char		uc;
	int					beg;
	int					i;

	i = -1;
	if (mask->width > 1)
		(mask->plh_size = mask->width);
	else
		(mask->plh_size = 1);
	if (ft_strchr(mask->flag, '-'))
		(beg = 0);
	else
		(beg = mask->plh_size - 1);
	uc = (unsigned char)va_arg(ap, unsigned int);
	if (ft_strchr(mask->flag, '-'))
		(mask->plh_algn = 1);
	else
		(mask->plh_algn = 0);
	if (ft_strchr(mask->flag, '0') && !(mask->plh_algn) && !(mask->precision))
		(mask->plh_w_ch = '0');
	else
		(mask->plh_w_ch = ' ');
	while (++i < mask->plh_size)
		(i == beg) ? (ft_putchar_fd(uc, 1)) : (ft_putchar_fd(mask->plh_w_ch,\
		1));
}

static void				ft_print_c_get_wcharout(va_list ap, t_mask *mask)
{
	wchar_t				uc;
	int					beg;
	int					i;

	i = -1;
	if (mask->width > 1)
		(mask->plh_size = mask->width);
	else
		(mask->plh_size = 1);
	if (ft_strchr(mask->flag, '-'))
		(beg = 0);
	else
		(beg = mask->plh_size - 1);
	uc = (wchar_t)va_arg(ap, wchar_t);
	while (++i < mask->plh_size)
		(i == beg) ? (ft_putchar_fd(uc, 1)) : (ft_putchar_fd(' ', 1));
}

int						ft_print_c(va_list ap, t_mask *mask)
{
	int					len;

	if (!(ft_strncmp(mask->length, "l", 1)))
		ft_print_c_get_wcharout(ap, mask);
	else
		ft_print_c_get_strout(ap, mask);
	len = mask->plh_size;
	free(mask);
	return (len);
}
