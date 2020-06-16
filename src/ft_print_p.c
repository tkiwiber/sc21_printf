/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:46 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/06/16 12:14:29 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_print_p_getnbr(va_list ap, char up)
{	
		return ft_ltoa_x((unsigned long int)va_arg(ap, unsigned long int), 16, up);
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
	(mask->width > mask->plh_old) ? (mask->plh_wdth = mask->width - \
	mask->plh_old) : (mask->plh_wdth = 0);
	mask->plh_size = mask->plh_old + mask->plh_wdth;
	(ft_strchr(mask->flag, '-')) ? (mask->plh_algn = 1) : (mask->plh_algn = 0);
	(ft_strchr(mask->flag, '0') && !(mask->plh_algn) && !(mask->precision)) ?\
	(mask->plh_w_ch = '0') : (mask->plh_w_ch = ' ');
}

static void			ft_print_add_width(char *str_out, t_mask *mask)
{
	if (mask->plh_wdth)
		ft_memset(str_out, (mask->plh_algn) ? 32 : (mask->plh_w_ch),	mask->width);
}

static void			ft_print_add_word(char *str_out, char *str, t_mask *mask)
{
	int				beg;

	beg = mask->plh_size - mask->plh_old - (mask->plh_algn ? mask->plh_wdth : 0);
	ft_memcpy(str_out + beg, str, mask->plh_old);
}

static char			*ft_print_p_get_strout(va_list ap, t_mask *mask)
{
	char			*str_out;
	char			*str_proto1;
	char			*str_proto2;
    char            up;
	int				beg;

    up = 0;
	str_proto1 = ft_print_p_getnbr(ap, up);
	if (str_proto1[0] == '0' && str_proto1[1] == '\0')
	{
		if (!(str_proto2 = (char*)malloc(sizeof(char) * (4))))
			return (NULL);
		ft_memcpy(str_proto2, "0x0", 3);
	}
	else
	{
		if (!(str_proto2 = (char*)malloc(sizeof(char) * (sizeof(uintptr_t) + 3))))
			return (NULL);
		ft_memset(str_proto2, '0', sizeof(uintptr_t));
		(((int)sizeof(uintptr_t) - (int)ft_strlen(str_proto1)) > 0) ? \
		(beg = (int)sizeof(uintptr_t) - (int)ft_strlen(str_proto1)) : (beg = 0);
		ft_memcpy(str_proto2, "0x", 2);
		ft_memcpy(str_proto2 + 2 + beg, str_proto1, ft_strlen(str_proto1));
	}
	ft_print_conversion(str_proto2, mask);
	if (!(str_out = (char*)malloc(sizeof(char) * (mask->plh_size + 3))))
		return (NULL);
    ft_print_add_width(str_out, mask);
	ft_print_add_word(str_out, str_proto2, mask);
	str_out[mask->plh_size] = '\0';
	free(str_proto1);
	free(str_proto2);
	return (str_out);
}

int 				ft_print_p(va_list ap, t_mask *mask)
{
	char			*str_to_out;
	int				len;

	str_to_out = ft_print_p_get_strout(ap, mask);
	len = ft_strlen(str_to_out);
	ft_putstr_fd(str_to_out, 1);
	free(str_to_out);
	free(mask);
	return (len);
}
