/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:46 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/16 12:16:00 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_print_conversion(char *str_proto, t_mask *mask)
{
	mask->prefix = 2;
	mask->plh_w_ch = ' ';
	mask->plh_old = (int)ft_strlen(str_proto);
	(mask->precision < 0) ? (mask->precision *= 0) : (mask->precision *= 1);
	(mask->precision < mask->plh_old) ? (mask->plh_prcs = mask->plh_old) :\
	(mask->plh_prcs = mask->precision);
	if (mask->trunc && !ft_strncmp(str_proto, "0", 2))
		(mask->plh_prcs = 0);
	(mask->width > mask->plh_prcs + mask->prefix) ? (mask->plh_wdth = \
	mask->width) : (mask->plh_wdth = 0);
	(mask->plh_wdth) ? (mask->plh_size = mask->plh_wdth) :\
	(mask->plh_size = mask->plh_prcs + mask->prefix);
	(ft_strchr(mask->flag, '-')) ? (mask->plh_algn = 1)\
	: (mask->plh_algn = 0);
}

static void				ft_print_add_prefix(char *str_out, t_mask *mask)
{
	int					beg;

	(mask->plh_algn) ? (beg = 0) :\
	(beg = mask->plh_size - mask->plh_prcs - mask->prefix);
	ft_memcpy(str_out + beg, "0x", mask->prefix);
}

static void				ft_print_add_word(char *str_out, char *str, \
t_mask *mask)
{
	int					beg;

	if (mask->plh_algn)
		beg = mask->prefix + mask->plh_prcs - mask->plh_old;
	else
		beg = mask->plh_size - mask->plh_old;
	ft_memcpy(str_out + beg, str, mask->plh_old);
}

static char				*ft_print_p_get_strout(va_list ap, t_mask *mask)
{
	char				*str_out;
	char				*str_proto;
	char				up;
	int					beg;
	size_t				ul;

	up = 0;
	ul = (size_t)(va_arg(ap, size_t));
	(ul < 0) ? (ul *= ~ul) : (ul *= 1);
	str_proto = ft_ltoa_x(ul, 16, up);
	ft_print_conversion(str_proto, mask);
	if (!(str_out = (char*)malloc(sizeof(char) * (mask->plh_size + 1))))
		return (NULL);
	if (mask->plh_wdth)
		ft_memset(str_out, (mask->plh_algn) ? 32 : (mask->plh_w_ch),\
		mask->width);
	(mask->plh_algn) ? (beg = mask->prefix) :\
	(beg = mask->plh_size - mask->plh_prcs);
	ft_memset(str_out + beg, '0', mask->plh_prcs);
	ft_print_add_prefix(str_out, mask);
	if (!(mask->trunc && !ft_strncmp(str_proto, "0", 2)))
		ft_print_add_word(str_out, str_proto, mask);
	str_out[mask->plh_size] = '\0';
	free(str_proto);
	return (str_out);
}

int						ft_print_p(va_list ap, t_mask *mask)
{
	char				*str_to_out;
	int					len;

	str_to_out = ft_print_p_get_strout(ap, mask);
	len = ft_strlen(str_to_out);
	ft_putstr_fd(str_to_out, 1);
	free(str_to_out);
	return (len);
}
