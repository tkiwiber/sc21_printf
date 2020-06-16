/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:46 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/06/16 13:53:20 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_print_x_getnbr(va_list ap, t_mask *mask, char up)
{	
    if (!(ft_strncmp(mask->length, "ll", 2)))
		return ft_ltoa_x((unsigned long long int)va_arg(ap, unsigned long long  int), 16, up);
	else if (!(ft_strncmp(mask->length, "l", 1)))
		return ft_ltoa_x((unsigned long int)va_arg(ap, unsigned long long  int), 16, up);
	else if (!(ft_strncmp(mask->length, "hh", 2)))
		return ft_itoa_x((unsigned char)va_arg(ap, unsigned long long  int), 16, up);
	else if (!(ft_strncmp(mask->length, "h", 1)))
		return ft_itoa_x((unsigned short int)va_arg(ap, unsigned long long  int), 16, up);
	else
		return ft_itoa_x((unsigned int)va_arg(ap, unsigned int), 16, up);
}

static void			ft_print_conversion(char *str_proto, t_mask *mask)
{
	mask->plh_old = (int)ft_strlen(str_proto);
	(ft_strchr(mask->flag, 32)) ? (mask->plh_s_ch = 32) : \
	(mask->plh_s_ch += 0);
	(ft_strchr(mask->flag, '+')) ? (mask->plh_s_ch = '+') : \
	(mask->plh_s_ch += 0);
	(str_proto[0] == '-') ? (mask->plh_s_ch = '-') : (mask->plh_s_ch += 0);
	mask->plh_sign = 0;
	mask->plh_old -= mask->plh_sign;
	(mask->precision > mask->plh_old) ?	(mask->plh_prcs = mask->precision - \
	mask->plh_old) : (mask->plh_prcs = 0);
	if (mask->plh_prcs)
		(mask->width > mask->precision + mask->plh_sign) ? (mask->plh_wdth =\
		mask->width - mask->precision - mask->plh_sign) : (mask->plh_wdth = 0);
	else
		(mask->width > mask->plh_old) ? (mask->plh_wdth =\
		mask->width - mask->plh_old - mask->plh_sign) : (mask->plh_wdth = 0);
	
	mask->plh_size = mask->plh_old + mask->plh_prcs + mask->plh_wdth + \
	mask->plh_sign;
	(ft_strchr(mask->flag, '-')) ? (mask->plh_algn = 1) : (mask->plh_algn = 0);
	(ft_strchr(mask->flag, '0') && !(mask->plh_algn) && !(mask->precision)) ?\
	(mask->plh_w_ch = '0') : (mask->plh_w_ch = ' ');
}

static void			ft_print_add_width(char *str_out, t_mask *mask)
{
	if (mask->plh_wdth)
		ft_memset(str_out, (mask->plh_algn) ? 32 : (mask->plh_w_ch),	mask->width);
}

static void			ft_print_add_sign(char *str_out, t_mask *mask)
{
	int				beg;

	if (mask->plh_wdth && mask->plh_w_ch == '0')
		beg = 0;
	else
		beg = (mask->plh_algn ? 0 : mask->plh_wdth);
	ft_memset(str_out + beg, mask->plh_s_ch, mask->plh_sign);
}

static void			ft_print_add_precision(char *str_out, t_mask *mask)
{
	int				beg;
	
	beg = mask->plh_sign + (mask->plh_algn ? 0 : mask->plh_wdth);
	ft_memset(str_out + beg, '0', mask->plh_prcs);
}

static void			ft_print_add_word(char *str_out, char *str, t_mask *mask)
{
	int				beg;

	if (mask->plh_sign)
		beg = mask->plh_size - mask->plh_old - (mask->plh_algn ? mask->plh_wdth : 0);
	else
		beg = mask->plh_size - mask->plh_old - (mask->plh_algn ? mask->plh_wdth : 0);
	ft_memcpy(str_out + beg, str, mask->plh_old);
}

static char			*ft_print_x_get_strout(va_list ap, t_mask *mask)
{
	char			*str_out;
	char			*str_proto;
    char            up;
	
    (mask->type == 'X') ? (up = 1) : (up = 0);
	str_proto = ft_print_x_getnbr(ap, mask, up);
	ft_print_conversion(str_proto, mask);
	if (!(str_out = (char*)malloc(sizeof(char) * (mask->plh_size + 1))))
		return (NULL);
	ft_print_add_width(str_out, mask);
	ft_print_add_sign(str_out, mask);
	ft_print_add_precision(str_out, mask);
	if (!(((mask->trunc == 1) && ft_strncmp(str_proto, "0", ft_strlen(str_proto)) == 0)))
		ft_print_add_word(str_out, str_proto, mask);
	str_out[mask->plh_size] = '\0';
	free(str_proto);
	return (str_out);
}

int 				ft_print_x(va_list ap, t_mask *mask)
{
	char			*str_to_out;
	int				len;

	str_to_out = ft_print_x_get_strout(ap, mask);
	len = ft_strlen(str_to_out);
	ft_putstr_fd(str_to_out, 1);
	free(str_to_out);
	free(mask);
	return (len);
}
