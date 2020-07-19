/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:46 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/19 12:44:47 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_print_conversion(char *str_proto, t_mask *mask)
{
	mask->plh_old = (int)ft_strlen(str_proto);
	if (mask->precision <= 0)
		mask->plh_prcs = mask->plh_old;
	else if (mask->precision > mask->plh_old)
		mask->plh_prcs = mask->plh_old;
	else
		mask->plh_prcs = mask->precision;
	if (mask->trunc == 1)
		mask->plh_prcs = 0;
	if (mask->plh_prcs)
		(mask->width > mask->plh_prcs) ? (mask->plh_wdth = \
		mask->width - mask->plh_prcs) : (mask->plh_wdth = 0);
	else
		(mask->width > mask->plh_old) ? (mask->plh_wdth = \
		mask->width - mask->plh_old) : (mask->plh_wdth = 0);
	if (mask->plh_prcs)
		mask->plh_size = mask->plh_prcs + mask->plh_wdth;
	else
		mask->plh_size = mask->width;
	(ft_strchr(mask->flag, '-')) ? (mask->plh_algn = 1) :\
	(mask->plh_algn = 0);
	(ft_strchr(mask->flag, '0') && !(mask->plh_algn)) ? (mask->plh_w_ch = '0')\
	: (mask->plh_w_ch = ' ');
}

static char			*ft_print_s_get_strout(va_list ap, t_mask *mask)
{
	char			*str_out;
	char			*str_proto;
	int				beg;
	static char		null_str[] = "(null)";

	str_proto = (char *)va_arg(ap, char *);
	if (str_proto == NULL)
		str_proto = null_str;
	ft_print_conversion(str_proto, mask);
	(mask->plh_algn) ? (beg = 0) :\
	(beg = mask->plh_size - mask->plh_prcs);
	if (!(str_out = (char*)malloc(sizeof(char) * (mask->plh_size + 1))))
		return (NULL);
	ft_memset(str_out, mask->plh_w_ch, mask->plh_size);
	ft_memcpy(str_out + beg, str_proto, mask->plh_prcs);
	str_out[mask->plh_size] = '\0';
	return (str_out);
}

int					ft_print_s(va_list ap, t_mask *mask)
{
	char			*str_to_out;
	int				len;

	str_to_out = ft_print_s_get_strout(ap, mask);
	len = ft_strlen(str_to_out);
	ft_putstr_fd(str_to_out, 1);
	free(str_to_out);
	return (len);
}
