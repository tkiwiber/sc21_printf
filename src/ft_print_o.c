/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:46 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/14 15:51:58 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_print_o_getnbr(va_list ap, t_mask *mask, char up)
{
	if (!(ft_strncmp(mask->length, "ll", 2)))
		return (ft_ltoa_x((unsigned long long int)va_arg(ap,\
		unsigned long long int), 8, up));
	else if (!(ft_strncmp(mask->length, "l", 1)))
		return (ft_ltoa_x((unsigned long int)va_arg(ap,\
		unsigned long long int), 8, up));
	else if (!(ft_strncmp(mask->length, "hh", 2)))
		return (ft_itoa_x((unsigned char)va_arg(ap,\
		unsigned long long int), 8, up));
	else if (!(ft_strncmp(mask->length, "h", 1)))
		return (ft_itoa_x((unsigned short int)va_arg(ap,\
		unsigned long long int), 8, up));
	else
		return (ft_itoa_x((unsigned int)va_arg(ap, unsigned int), 8, up));
}

static void			ft_print_conversion(char *str_proto, t_mask *mask)
{
	(ft_strchr(mask->flag, '#') && str_proto[0] != '0') ? (mask->prefix = 1)\
	: (mask->prefix = 0);
	mask->plh_old = (int)ft_strlen(str_proto);
	(ft_strchr(mask->flag, 32)) ? (mask->plh_s_ch = 32) : \
	(mask->plh_s_ch += 0);
	(ft_strchr(mask->flag, '+')) ? (mask->plh_s_ch = '+') : \
	(mask->plh_s_ch += 0);
	(str_proto[0] == '-') ? (mask->plh_s_ch = '-') : (mask->plh_s_ch += 0);
	(mask->precision > mask->plh_old) ? (mask->plh_prcs = mask->precision -\
	mask->plh_old) : (mask->plh_prcs = 0);
	if (mask->plh_prcs)
		(mask->width > mask->precision + mask->prefix * 1) ? (mask->plh_wdth =\
		mask->width - mask->precision - mask->prefix * 1) :\
		(mask->plh_wdth = 0);
	else
		(mask->width > mask->plh_old + mask->prefix * 1) ? (mask->plh_wdth = \
		mask->width - mask->plh_old - mask->prefix * 1) : (mask->plh_wdth = 0);
	mask->plh_size = mask->plh_old + mask->plh_prcs + mask->plh_wdth + \
	(mask->prefix * 1);
	(ft_strchr(mask->flag, '-')) ? (mask->plh_algn = 1)\
	: (mask->plh_algn = 0);
	(ft_strchr(mask->flag, '0') && !(mask->plh_algn) && !(mask->precision)) ?\
	(mask->plh_w_ch = '0') :\
	(mask->plh_w_ch = ' ');
}

static void			ft_print_add_word(char *str_out, char *str, t_mask *mask)
{
	int				beg;
	char			*prfx;

	(mask->type == 'o') ? (prfx = ft_strdup("0"))\
	: (prfx = ft_strdup("0"));
	beg = mask->plh_size - mask->plh_old - (mask->plh_algn ?\
	(mask->plh_wdth) : 0);
	if (mask->prefix)
	{
		if (ft_strchr(mask->flag, '0') && !mask->precision)
		{
			beg -= (mask->plh_prcs + mask->plh_wdth + 1);
			ft_memcpy(str_out + beg, prfx, 1);
			beg += (1 + mask->plh_wdth);
			ft_memcpy(str_out + beg, str, mask->plh_old);
			free(prfx);
			return ;
		}
		else
			ft_memcpy(str_out + beg - mask->plh_prcs - 1, prfx, 1);
	}
	ft_memcpy(str_out + beg, str, mask->plh_old);
	free(prfx);
}

static char			*ft_print_o_get_strout(va_list ap, t_mask *mask)
{
	char			*str_out;
	char			*str_proto;
	char			up;
	int				beg;

	(mask->type == 'X') ? (up = 1)\
	: (up = 0);
	str_proto = ft_print_o_getnbr(ap, mask, up);
	ft_print_conversion(str_proto, mask);
	if (!(str_out = (char*)malloc(sizeof(char) * (mask->plh_size + \
	(mask->prefix * 1) + 1))))
		return (NULL);
	if (mask->plh_wdth)
		ft_memset(str_out, (mask->plh_algn) ? 32 : (mask->plh_w_ch),\
		mask->width);
	beg = (mask->plh_algn ? 0 : mask->plh_wdth);
	ft_memset(str_out + beg, '0', mask->plh_prcs + mask->prefix * 1);
	if (!(((mask->trunc == 1) && ft_strncmp(str_proto, "0",\
	ft_strlen(str_proto)) == 0)))
		ft_print_add_word(str_out, str_proto, mask);
	str_out[mask->plh_size] = '\0';
	free(str_proto);
	return (str_out);
}

int					ft_print_o(va_list ap, t_mask *mask)
{
	char			*str_to_out;
	int				len;

	str_to_out = ft_print_o_get_strout(ap, mask);
	len = ft_strlen(str_to_out);
	ft_putstr_fd(str_to_out, 1);
	free(str_to_out);
	return (len);
}
