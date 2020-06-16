/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 19:03:43 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/06/16 12:27:25 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			    ft_print_pct_get_strout(t_mask *mask)
{
	unsigned char		uc;
	int					beg;
	int					i;
	
	i = -1;
	(mask->width > 1) ? (mask->plh_size = mask->width) : (mask->plh_size = 1);
	(ft_strchr(mask->flag, '-')) ? (beg = 0) : (beg = mask->plh_size - 1);
	uc = '%';
	(ft_strchr(mask->flag, '-')) ? (mask->plh_algn = 1) : (mask->plh_algn = 0);
	(ft_strchr(mask->flag, '0') && !(mask->plh_algn) && !(mask->precision)) ?\
	(mask->plh_w_ch = '0') : (mask->plh_w_ch = ' ');
	while (++i < mask->plh_size)
		(i == beg) ? (ft_putchar_fd(uc, 1)) : (ft_putchar_fd(mask->plh_w_ch, 1));
}

int 				ft_print_pct(va_list ap, t_mask *mask)
{
	int				len;
	va_list			p2;

	va_copy(p2, ap);
	ft_print_pct_get_strout(mask);
	len = mask->plh_size;
	free(mask);
	return (len);
}
